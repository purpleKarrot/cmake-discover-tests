// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <SDL3/SDL.h>
#include <SDL3/SDL_test.h>

static int test_addition(void *arg)
{
    SDLTest_AssertCheck(1 + 1 == 2, "1 + 1 should equal 2");
    return TEST_COMPLETED;
}

static int test_subtraction(void *arg)
{
    SDLTest_AssertCheck(2 - 1 == 1, "2 - 1 should equal 1");
    return TEST_COMPLETED;
}

static int test_string_compare(void *arg)
{
    SDLTest_AssertCheck(SDL_strcmp("hello", "hello") == 0, "\"hello\" should equal \"hello\"");
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference testAdditionCase = {
    test_addition,
    "Addition",
    "Test integer addition",
    TEST_ENABLED,
};

static const SDLTest_TestCaseReference testSubtractionCase = {
    test_subtraction,
    "Subtraction",
    "Test integer subtraction",
    TEST_ENABLED,
};

static const SDLTest_TestCaseReference *mathTestCases[] = {
    &testAdditionCase,
    &testSubtractionCase,
    NULL,
};

static SDLTest_TestSuiteReference mathTestSuite = {
    "Math",
    NULL,
    mathTestCases,
    NULL,
};

static const SDLTest_TestCaseReference testStringCompareCase = {
    test_string_compare,
    "compare",
    "Test string comparison",
    TEST_ENABLED,
};

static const SDLTest_TestCaseReference *stringTestCases[] = {
    &testStringCompareCase,
    NULL,
};

static SDLTest_TestSuiteReference stringTestSuite = {
    "String",
    NULL,
    stringTestCases,
    NULL,
};

static SDLTest_TestSuiteReference *testSuites[] = {
    &mathTestSuite,
    &stringTestSuite,
    NULL,
};

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "--list-tests") == 0)
    {
        for (int i = 0; testSuites[i] != NULL; ++i)
        {
            SDLTest_TestSuiteReference *suite = testSuites[i];
            SDL_Log("%s\n", suite->name);
        }
        return 0;
    }

    SDLTest_CommonState *state = SDLTest_CommonCreateState(argv, 0);
    SDLTest_TestSuiteRunner *runner = SDLTest_CreateTestSuiteRunner(state, testSuites);
    if (!SDLTest_CommonDefaultArgs(state, argc, argv))
    {
        return 1;
    }

    int result = SDLTest_ExecuteTestSuiteRunner(runner);

    SDLTest_DestroyTestSuiteRunner(runner);
    SDLTest_CommonDestroyState(state);
    return result;
}
