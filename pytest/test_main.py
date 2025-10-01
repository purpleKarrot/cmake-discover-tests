# SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
# SPDX-License-Identifier: ISC


class TestMath:
    def test_addition(self):
        assert 1 + 1 == 2

    def test_subtraction(self):
        assert 2 - 1 == 1


class TestString:
    def test_compare(self):
        assert "hello" == "hello"


def test_free():
    assert 2 == 2
