# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(SDL3 REQUIRED COMPONENTS SDL3_test)

add_executable(sdl3_test_runner main.c)
target_link_libraries(sdl3_test_runner
  SDL3::SDL3
  SDL3::SDL3_test
)

discover_tests(sdl3_test_runner
  DISCOVERY_ARGS        --list-tests
  DISCOVERY_MATCH       [[.+]]
  TEST_NAME_REPLACEMENT [[sdl3.\0]]
  TEST_ARGS_REPLACEMENT [[--filter \0]]
)
