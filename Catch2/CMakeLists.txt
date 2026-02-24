# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(Catch2 REQUIRED)

add_executable(catch2_test_runner main.cpp)
target_link_libraries(catch2_test_runner PRIVATE Catch2::Catch2WithMain)

discover_tests(COMMAND catch2_test_runner
  DISCOVERY_ARGS --list-tests
  DISCOVERY_MATCH "  ([^ ].*)"
  TEST_NAME "catch2.\\1"
  TEST_ARGS "\\1"
)
