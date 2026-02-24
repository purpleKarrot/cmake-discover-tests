// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <cmocka.h>

static void test_math_addition(void **state)
{
    (void)state;
    assert_int_equal(1 + 1, 2);
}

static void test_math_subtraction(void **state)
{
    (void)state;
    assert_int_equal(2 - 1, 1);
}

int math(int argc, char *argv[])
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_math_addition),
        cmocka_unit_test(test_math_subtraction),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
