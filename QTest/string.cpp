// SPDX-FileCopyrightText: 2025 Daniel Pfeifer <daniel@pfeifer-mail.de>
// SPDX-License-Identifier: ISC

#include <QTest>

class StringTests : public QObject
{
    Q_OBJECT

  private slots:
    void Compare()
    {
        QCOMPARE(QString("hello"), "hello");
    }
};

QTEST_MAIN(StringTests)

#include "string.moc"
