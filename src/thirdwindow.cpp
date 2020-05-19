#include "thirdwindow.h"
#include "ui_thirdwindow.h"
    QString login;
    QString level1 = "text.txt";
    QTime t(0,0,0);
    ThirdWindow::ThirdWindow(QWidget *parent) :
    QMainWindow(parent),
    thirdwindow(new Ui::ThirdWindow)
{
    thirdwindow->setupUi(this);
    thirdwindow->textEdit->setReadOnly(true);
}
ThirdWindow::~ThirdWindow()
{
    delete thirdwindow;
}
void ThirdWindow::on_pushButton_clicked()
{
    QString str = thirdwindow->textEdit->toPlainText();
        QString text = thirdwindow->lineEdit->text();
        if (text == str){
            QMessageBox::information(this,"Результат","Все правильно...");
        } else {
            QMessageBox::information(this,"Результат","Допущены ошибки...");
        }
        close();
        thirdwindow->lineEdit->clear();
}

void ThirdWindow::on_pushButton_2_clicked()
{
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    QFile level(":/res/levels/firstLevel.txt");
          if(!level.open(QFile::ReadOnly | QFile::Text)){
             QMessageBox::information(this,"Error","file not open");
             return;
        }
        QString buffer = level.readAll();
        thirdwindow->statusbar->showMessage(buffer);
        level.close();
        thirdwindow->textEdit->setText(buffer);
        thirdwindow->lineEdit->clear();
        thirdwindow->statusbar->showMessage(login);
}

void ThirdWindow::on_pushButton_3_clicked()
{
    close();
    QMessageBox::information(this,"Результат","Перешло");
}

void ThirdWindow::onTimeout()
{
    t = t.addSecs(1);
    thirdwindow->timertext->setText(t.toString("mm:ss"));
}
