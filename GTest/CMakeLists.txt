# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(gtest_test_runner main.cpp)
target_link_libraries(gtest_test_runner PRIVATE GTest::gtest_main)

gtest_discover_tests(gtest_test_runner
  TEST_PREFIX "gtest."
  DISCOVERY_MODE PRE_TEST
)
