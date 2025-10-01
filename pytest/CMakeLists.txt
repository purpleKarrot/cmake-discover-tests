# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(Python3 COMPONENTS Interpreter REQUIRED)

# discover_tests(Python3::Interpreter -m pytest
#   DISCOVERY_ARGS        --collect-only --quiet
#   DISCOVERY_MATCH       [[test_([^:]+)\.py(::Test([^:]+))?::test_(.+)]]
#   TEST_NAME_REPLACEMENT [[pytest.\3.\4]]
#   TEST_ARGS_REPLACEMENT [[\0]]
#   PROPERTIES
#     WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
# )

discover_tests(Python3::Interpreter -m pytest
  DISCOVERY_ARGS        --collect-only --quiet
  DISCOVERY_MATCH       [[(test_[^:]+\.py)::Test([^:]+)::test_(.+)]]
  TEST_NAME_REPLACEMENT [[pytest.\2.\3]]
  TEST_ARGS_REPLACEMENT [[\0]]
  PROPERTIES
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# discover_tests(Python3::Interpreter -m pytest
#   DISCOVERY_ARGS        --collect-only --quiet
#   DISCOVERY_MATCH       [[(test_[^:]+\.py)::test_(.+)]]
#   TEST_NAME_REPLACEMENT [[pytest.\2]]
#   TEST_ARGS_REPLACEMENT [[\0]]
#   PROPERTIES
#     WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
# )
