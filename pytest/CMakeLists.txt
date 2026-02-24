# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(Python3 COMPONENTS Interpreter REQUIRED)

discover_tests(COMMAND Python3::Interpreter -B -m pytest -p no:cacheprovider
  DISCOVERY_ARGS --collect-only --quiet
  DISCOVERY_MATCH [[test_([^:]+)\.py(::Test([^:]+))?::test_(.+)]]
  TEST_NAME [[pytest.\3.\4]]
  TEST_ARGS [[\0]]
  PROPERTIES
    LABELS "pytest;\\3"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
