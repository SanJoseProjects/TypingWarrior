#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QTest>
#include "test_function.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("TypingWarrior");
  w.show();
  QTest::qExec(new test_function, argc, argv);
  w.setWindowTitle("TypingWarrior");w.show();
  return a.exec();
}
