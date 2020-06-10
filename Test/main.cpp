#include "test_function.h"
#include <QApplication>
#include <QTest>
#include <iostream>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new test_function, argc, argv);
}
