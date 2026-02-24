// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#define BOOST_TEST_MODULE main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Math)

BOOST_AUTO_TEST_CASE(Addition)
{
    BOOST_TEST(1 + 1 == 2);
}

BOOST_AUTO_TEST_CASE(Subtraction)
{
    BOOST_TEST(2 - 1 == 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(String)

BOOST_AUTO_TEST_CASE(Compare)
{
    BOOST_TEST(std::string("hello") == "hello");
}

BOOST_AUTO_TEST_SUITE_END()
