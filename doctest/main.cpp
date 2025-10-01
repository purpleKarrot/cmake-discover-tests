// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_SUITE("Math")
{
    TEST_CASE("Addition")
    {
        CHECK(1 + 1 == 2);
    }

    TEST_CASE("Subtraction")
    {
        CHECK(2 - 1 == 1);
    }
}

TEST_SUITE("String")
{
    TEST_CASE("Compare")
    {
        CHECK(std::string("hello") == std::string("hello"));
    }
}
