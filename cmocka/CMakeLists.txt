# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(cmocka REQUIRED)

create_test_sourcelist(SRC main.c math.c string.c)
add_executable(cmocka_test_runner ${SRC})
target_link_libraries(cmocka_test_runner PRIVATE cmocka::cmocka)

discover_tests(COMMAND cmocka_test_runner
  DISCOVERY_ARGS -N
  DISCOVERY_MATCH ".+"
  TEST_NAME "cmocka.\\0"
  TEST_ARGS "\\0"
)
