// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <gtest/gtest.h>

TEST(Math, Addition)
{
    EXPECT_EQ(1 + 1, 2);
}

TEST(Math, DISABLED_Subtraction)
{
    EXPECT_EQ(2 - 1, 1);
}

using MathMultiplyTest = ::testing::TestWithParam<std::tuple<int, int, int>>;

TEST_P(MathMultiplyTest, Multiply)
{
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int expected = std::get<2>(GetParam());
    EXPECT_EQ(a * b, expected);
}

INSTANTIATE_TEST_SUITE_P(Math, MathMultiplyTest,
                         ::testing::Values(std::make_tuple(2, 3, 6), std::make_tuple(-1, 5, -5),
                                           std::make_tuple(0, 10, 0), std::make_tuple(7, 1, 7)));

TEST(String, Compare)
{
    EXPECT_STREQ("hello", "hello");
}
