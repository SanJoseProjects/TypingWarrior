#include "mainwindow.h"
#include "ui_mainwindow.h"
    extern QString login;
MainWindow::MainWindow(QWidget *parent):
      QMainWindow(parent),
      firstwindow(new Ui::MainWindow)
{
    QMainWindow::setWindowTitle("tiping");
    firstwindow->setupUi(this);
    firstwindow->pushButton_2->setEnabled(false);
    QRegExp exp("[a-zA-Z0-9]{3,15}");
    firstwindow->lineEdit->setValidator(new QRegExpValidator(exp, this));
    connect(firstwindow->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(okEnabled()));

}

MainWindow::~MainWindow()
{
    delete firstwindow;
}

void MainWindow::okEnabled(){
    firstwindow->pushButton_2->setEnabled(firstwindow->lineEdit->hasAcceptableInput());
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
