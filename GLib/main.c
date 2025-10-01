// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <glib.h>

static void test_addition(void)
{
    g_assert_cmpint(1 + 1, ==, 2);
}

static void test_subtraction(void)
{
    g_assert_cmpint(2 - 1, ==, 1);
}

static void test_string_compare(void)
{
    g_assert_cmpstr("hello", ==, "hello");
}

int main(int argc, char **argv)
{
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/math/addition", test_addition);
    g_test_add_func("/math/subtraction", test_subtraction);
    g_test_add_func("/string/compare", test_string_compare);

    return g_test_run();
}
