#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
    extern QString login;
MainWindow::MainWindow(QWidget *parent):
      QMainWindow(parent),
      firstwindow(new Ui::MainWindow)
{
    QMainWindow::setWindowTitle("tiping");
    firstwindow->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete firstwindow;
}


void MainWindow::on_pushButton_clicked()
{
    close();
}
void MainWindow::on_pushButton_2_clicked()
{
    secondwindow = new SecondWindow(this);
    secondwindow->setWindowTitle ("TypingWarrior");
    secondwindow->show();
    QString login = firstwindow->lineEdit->text();
    firstwindow->statusbar->showMessage(login);
}
