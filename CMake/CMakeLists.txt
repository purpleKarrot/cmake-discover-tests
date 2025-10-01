# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

create_test_sourcelist(SRC main.c math.c string.c)
add_executable(cmake_test_driver ${SRC})

# TODO: generated test driver has no option to list all tests

# discover_tests(cmake_test_driver
#   DISCOVERY_ARGS        [[-]]
#   DISCOVERY_MATCH       [[([^(]*)\(\)]]
#   TEST_NAME_REPLACEMENT [[cmake.\1]]
#   TEST_ARGS_REPLACEMENT [[\1]]
# )
