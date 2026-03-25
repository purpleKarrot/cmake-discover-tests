# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(doctest REQUIRED)

add_executable(doctest_test_runner main.cpp)
target_link_libraries(doctest_test_runner PRIVATE doctest::doctest)

discover_tests(COMMAND doctest_test_runner
  DISCOVERY_ARGS --list-test-suites
  DISCOVERY_MATCH "[^[=].*"
  TEST_NAME "doctest.\\0"
  TEST_ARGS "--test-suite=\\0"
)
