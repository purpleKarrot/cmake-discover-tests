# CMake `discover_tests()` Examples

This repository is a work in progress and is not compatible with any released
version of CMake.

To build and test the examples, you'll need a CMake build from my
`discover-tests` branch:
https://gitlab.kitware.com/purpleKarrot/cmake/-/tree/discover-tests

## Notes:

In [Catch2](https://github.com/catchorg/Catch2), a *test case* is the top level
entity and may contain multiple *sections*. The `--list-tests` option prints the
names of all test cases. There is no way to get information about individual
sections. Catch2 also has a concept of *tags*, which are listed in the human
readable output in a way that does not make them easy to parse. Catch2 ships its
own `catch_discover_tests` command which invokes the driver with
`--list-tests --reporter json` and then extracts tag information from JSON.

In [doctest](https://github.com/doctest/doctest), the top level entity is the
*test suite* which may contain multiple *test cases*. It provides the options
`--list-test-suites` and `--list-test-cases` to get the names of test suites and
test cases respectively. It also ships a `doctest_discover_tests` command for
CMake, which first invokes the driver with `--list-test-cases` and then again
with `--test-case=${test} --list-test-suites` for each discovered test in order
to collect values that are added as `LABELS`. That means: If identically named
test cases are defined in multiple test suites, they will be defined as a single
test with multiple labels.

With [Qt Test](https://doc.qt.io/qt-6/qttest-index.html) it is not directly
possible to link tests for multiple classes to a single executable. The normal
approach is to have one test driver per *class*, wich can have multiple test
*functions*. The list of functions can be retrieved with `-functions`.

The [GLib Testing Framework](https://docs.gtk.org/glib/testing.html) supports
arbitrarily deep nesting, where each test is identified by a path. Tests can
be listed with the `-l` option.

[cmocka](https://cmocka.org/) and
[Boost lightweight_test](https://www.boost.org/doc/libs/latest/libs/core/doc/html/core/lightweight_test.html)
both provide assertion macros only without a dedicated approach for test
organization. Both testing frameworks can be easily combined with CMake's
`create_test_sourcelist` command.

[Boost.Test](https://www.boost.org/doc/libs/latest/libs/test/doc/html/index.html)
allows arbitrarily deep nesting. It provides the `--list_content` option to
print the test tree in human readable form to `stderr`. A wrapper will be
necessary to flatten the tree and write the tests to `stdout`.
