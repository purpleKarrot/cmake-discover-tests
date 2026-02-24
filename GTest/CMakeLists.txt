# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(GTest REQUIRED)

add_executable(gtest_test_runner main.cpp)
target_link_libraries(gtest_test_runner PRIVATE GTest::gtest_main)

discover_tests(COMMAND gtest_test_runner
  DISCOVERY_ARGS --gtest_list_tests
  DISCOVERY_MATCH "([^.]+)\\."
  TEST_NAME "gtest.\\1"
  TEST_ARGS "--gtest_filter=\\1.*"
)
