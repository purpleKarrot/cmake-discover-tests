// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <boost/core/lightweight_test.hpp>

int math(int argc, char *argv[])
{
    BOOST_TEST(1 + 1 == 2);
    BOOST_TEST(2 - 1 == 1);

    return boost::report_errors();
}
