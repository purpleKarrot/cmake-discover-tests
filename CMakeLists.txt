# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC

cmake_minimum_required(VERSION 4.1)
project(DiscoverTests)

enable_testing()
include(DiscoverTests.cmake)

add_subdirectory(Catch2)
add_subdirectory(CMake)
add_subdirectory(doctest)
add_subdirectory(GLib)
add_subdirectory(GTest)
add_subdirectory(pytest)
add_subdirectory(QTest)
add_subdirectory(SDL3)
