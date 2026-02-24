# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLib REQUIRED IMPORTED_TARGET glib-2.0)

add_executable(glib_test_runner main.c)
target_link_libraries(glib_test_runner PRIVATE PkgConfig::GLib)

discover_tests(COMMAND glib_test_runner
  DISCOVERY_ARGS -l
  DISCOVERY_MATCH "# /(.*)"
  TEST_NAME "glib/\\1"
  TEST_ARGS -p "/\\1"
)
