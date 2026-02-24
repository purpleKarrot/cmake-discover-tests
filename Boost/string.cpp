// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <boost/core/lightweight_test.hpp>

int string(int argc, char *argv[])
{
    BOOST_TEST(std::string("hello") == "hello");

    return boost::report_errors();
}
