# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

if(POLICY CMP0156)
  cmake_policy(SET CMP0156 OLD)
endif()

find_package(Qt6 REQUIRED COMPONENTS Test)

qt_add_executable(qt_test_math_runner math.cpp)
target_link_libraries(qt_test_math_runner PRIVATE Qt::Test)
set_property(TARGET qt_test_math_runner PROPERTY AUTOMOC ON)

qt_add_executable(qt_test_string_runner string.cpp)
target_link_libraries(qt_test_string_runner PRIVATE Qt::Test)
set_property(TARGET qt_test_string_runner PROPERTY AUTOMOC ON)

discover_tests(COMMAND qt_test_math_runner
  DISCOVERY_ARGS -functions
  DISCOVERY_MATCH [[([^(]*)\(\)]]
  TEST_NAME [[qt.Math.\1]]
  TEST_ARGS [[\1]]
)

discover_tests(COMMAND qt_test_string_runner
  DISCOVERY_ARGS -functions
  DISCOVERY_MATCH [[([^(]*)\(\)]]
  TEST_NAME [[qt.String.\1]]
  TEST_ARGS [[\1]]
)
