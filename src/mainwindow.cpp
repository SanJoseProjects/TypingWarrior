#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), firstwindow(new Ui::MainWindow)
{
    QMainWindow::setWindowTitle("tiping");
    firstwindow->setupUi(this);
    firstwindow->pushButton_start->setEnabled(false);
    QRegExp exp("[a-zA-Z0-9]{3,15}");
    firstwindow->lineEdit->setValidator(new QRegExpValidator(exp, this));
    connect(firstwindow->lineEdit,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(okEnabled()));
}

MainWindow::~MainWindow()
{
    delete firstwindow;
}

void MainWindow::okEnabled()
{
    firstwindow->pushButton_start->setEnabled(
            firstwindow->lineEdit->hasAcceptableInput());
}
void MainWindow::on_pushButton_exit_clicked()
{
    close();
}
void MainWindow::on_pushButton_start_clicked()
{
    login = firstwindow->lineEdit->text();
    firstwindow->statusbar->showMessage(login);
    thirdwindow = new ThirdWindow(this, login);
    thirdwindow->setWindowTitle("TypingWarrior");
    thirdwindow->show();
}

void MainWindow::on_pushButton_record_clicked()
{
    secondwindow = new SecondWindow(this);
    secondwindow->show();
    secondwindow->setWindowTitle("TypingWarrior");
}
void MainWindow::closeEvent(QCloseEvent* event)
{
    event->ignore();
    if (QMessageBox::Yes
        == QMessageBox::question(
                this,
                "Закрыть?",
                "Уверены?",
                QMessageBox::Yes | QMessageBox::No)) {
        event->accept();
    }
}
