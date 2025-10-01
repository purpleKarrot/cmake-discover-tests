// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Math - Addition", "[math]")
{
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Math - Subtraction", "[math]")
{
    REQUIRE(2 - 1 == 1);
}

TEST_CASE("String - Compare", "[string]")
{
    REQUIRE(std::string("hello") == "hello");
}
