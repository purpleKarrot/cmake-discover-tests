// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <QTest>

class MathTest : public QObject
{
    Q_OBJECT

  private slots:
    void Addition()
    {
        QCOMPARE(1 + 1, 2);
    }

    void Subtraction()
    {
        QCOMPARE(2 - 1, 1);
    }
};

QTEST_MAIN(MathTest)

#include "math.moc"
