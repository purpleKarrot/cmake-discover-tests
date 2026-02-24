// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <cmocka.h>

static void test_string_compare(void **state)
{
    (void)state;
    assert_string_equal("hello", "hello");
}

int string(int argc, char *argv[])
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_string_compare),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
