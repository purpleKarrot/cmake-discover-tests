# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(boost_test_runner main.cpp)
target_link_libraries(boost_test_runner PRIVATE Boost::unit_test_framework)

# Does not work, as the list is not printed to stdout...
discover_tests(COMMAND boost_test_runner
  DISCOVERY_ARGS --list_content
  DISCOVERY_MATCH ".+"
  TEST_NAME "boost.\\0"
  TEST_ARGS "--run_test=\\0"
)

create_test_sourcelist(SRC light.cpp math.cpp string.cpp)
add_executable(boost_test_runner_light ${SRC})
target_link_libraries(boost_test_runner_light PRIVATE Boost::headers)

discover_tests(COMMAND boost_test_runner_light
  DISCOVERY_ARGS -N
  DISCOVERY_MATCH ".+"
  TEST_NAME "Boost.Light.\\0"
  TEST_ARGS "\\0"
)
