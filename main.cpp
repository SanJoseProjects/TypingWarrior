#include <iostream>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ("TypingWarrior");
    w.show();
    extern QString login;
    return a.exec();
}
