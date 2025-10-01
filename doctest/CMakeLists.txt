# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(doctest REQUIRED)

add_executable(doctest_test_runner main.cpp)
target_link_libraries(doctest_test_runner PRIVATE doctest::doctest)

discover_tests(doctest_test_runner
  DISCOVERY_ARGS        [[--list-test-cases]]
  DISCOVERY_MATCH       [[[^[=].*]]
  TEST_NAME_REPLACEMENT [[doctest.cases.\0]]
  TEST_ARGS_REPLACEMENT [[--test-case=\0]]
)

discover_tests(doctest_test_runner
  DISCOVERY_ARGS        [[--list-test-suites]]
  DISCOVERY_MATCH       [[[^[=].*]]
  TEST_NAME_REPLACEMENT [[doctest.suites.\0]]
  TEST_ARGS_REPLACEMENT [[--test-suite=\0]]
)
