# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

function(__join_args out list)
  set(result "")
  foreach(arg IN LISTS ${list})
    if(arg MATCHES " ")
      string(APPEND result "\"${arg}\" ")
    else()
      string(APPEND result "${arg} ")
    endif()
  endforeach()
  string(REGEX REPLACE " $" "" result "${result}")
  set(${out} "${result}" PARENT_SCOPE)
endfunction()

function(discover_tests target)
  set(oneValueArgs DISCOVERY_MATCH TEST_NAME_REPLACEMENT TEST_ARGS_REPLACEMENT)
  set(multiValueArgs DISCOVERY_ARGS PROPERTIES)
  cmake_parse_arguments(PARSE_ARGV 1 arg "" "${oneValueArgs}" "${multiValueArgs}")

  if(NOT arg_DISCOVERY_MATCH MATCHES "^\\^")
    string(PREPEND arg_DISCOVERY_MATCH "^")
  endif()

  if(NOT arg_DISCOVERY_MATCH MATCHES "\\$$")
    string(APPEND arg_DISCOVERY_MATCH "$")
  endif()

  __join_args(common_args arg_UNPARSED_ARGUMENTS)
  __join_args(discovery_args arg_DISCOVERY_ARGS)

  get_property(has_counter TARGET ${target} PROPERTY CTEST_DISCOVERED_TEST_COUNTER SET)
  if(has_counter)
    get_property(counter TARGET ${target} PROPERTY CTEST_DISCOVERED_TEST_COUNTER)
    math(EXPR counter "${counter} + 1")
  else()
    set(counter 1)
  endif()
  set_property(TARGET ${target} PROPERTY CTEST_DISCOVERED_TEST_COUNTER ${counter})

  set(file_base "${CMAKE_CURRENT_BINARY_DIR}/${target}[${counter}]")
  set(include_file "${file_base}_include.cmake")

  set(workdir_content)
  set(properies_content)

  list(LENGTH arg_PROPERTIES properties_len)
  if(properties_len GREATER "0")
    math(EXPR num_properties "${properties_len} / 2")
    foreach(i RANGE 0 ${num_properties} 2)
      math(EXPR value_index "${i} + 1")
      list(GET arg_PROPERTIES ${i} name)
      list(GET arg_PROPERTIES ${value_index} value)
      if(value MATCHES "\\\\")
        string(APPEND properies_content "    string(REGEX REPLACE [[${arg_DISCOVERY_MATCH}]] [[${value}]] prop_${name} \"\${line}\")\n")
        set(value "\${prop_${name}}")
      endif()
      string(APPEND properies_content "    set_tests_properties(\"\${test_name}\" PROPERTIES \"${name}\" \"${value}\")\n")
      if(name STREQUAL "WORKING_DIRECTORY")
        set(workdir_content "  WORKING_DIRECTORY [[${value}]]\n")
      endif()
    endforeach()
  endif()

  string(CONCAT include_content
    "set(runner   [[$<TARGET_FILE:${target}>]])\n"
    "set(launcher [[$<TARGET_PROPERTY:${target},TEST_LAUNCHER>]])\n"
    "set(emulator [[$<$<BOOL:${CMAKE_CROSSCOMPILING}>:$<TARGET_PROPERTY:${target},CROSSCOMPILING_EMULATOR>>]])\n"
    "\n"
    "execute_process(\n"
    "  COMMAND \${launcher} \${emulator} \${runner} ${common_args} ${discovery_args}\n"
    ${workdir_content}
    "  OUTPUT_VARIABLE output OUTPUT_STRIP_TRAILING_WHITESPACE\n"
    "  ERROR_VARIABLE  output ERROR_STRIP_TRAILING_WHITESPACE\n"
    "  COMMAND_ERROR_IS_FATAL ANY\n"
    ")\n"
    "\n"
    "string(REPLACE \"\\n\" \";\" lines \"\${output}\")\n"
    "foreach(line IN LISTS lines)\n"
    "  if(line MATCHES [[${arg_DISCOVERY_MATCH}]])\n"
    "    string(REGEX REPLACE [[${arg_DISCOVERY_MATCH}]] [[${arg_TEST_NAME_REPLACEMENT}]] test_name \"\${line}\")\n"
    "    string(REGEX REPLACE [[${arg_DISCOVERY_MATCH}]] [[${arg_TEST_ARGS_REPLACEMENT}]] test_args \"\${line}\")\n"
    "    separate_arguments(test_args)\n"
    "    add_test(\"\${test_name}\" \${launcher} \${emulator} \${runner} ${common_args} \${test_args})\n"
    ${properies_content}
    "  endif()\n"
    "endforeach()\n"
  )

  get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
  if(is_multi_config)
    file(GENERATE
      OUTPUT "${file_base}_include-$<CONFIG>.cmake"
      CONTENT "${include_content}"
    )
    file(WRITE "${include_file}"
      "include(\"${file_base}_include-\${CTEST_CONFIGURATION_TYPE}.cmake\")"
    )
  else()
    file(GENERATE
      OUTPUT "${include_file}"
      CONTENT "${include_content}"
    )
  endif()

  set_property(DIRECTORY APPEND PROPERTY TEST_INCLUDE_FILES "${include_file}")
endfunction()
