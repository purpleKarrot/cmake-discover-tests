// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <gtest/gtest.h>

TEST(Math, Addition)
{
    EXPECT_EQ(1 + 1, 2);
}

TEST(Math, Subtraction)
{
    EXPECT_EQ(2 - 1, 1);
}

TEST(String, Compare)
{
    EXPECT_STREQ("hello", "hello");
}
