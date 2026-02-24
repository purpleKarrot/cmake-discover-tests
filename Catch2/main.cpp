// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <catch2/catch_all.hpp>

TEST_CASE("Math")
{
    SECTION("Addition")
    {
        CHECK(1 + 1 == 2);
    }

    SECTION("Subtraction")
    {
        CHECK(2 - 1 == 1);
    }
}

TEST_CASE("String")
{
    SECTION("Compare")
    {
        CHECK(std::string("hello") == "hello");
    }
}
