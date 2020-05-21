#include "thirdwindow.h"
#include "ui_thirdwindow.h"
    QString login;
    QString level1 = "text.txt";
    QTime t(0,0,0);
    int a;
    bool pause;
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

void ThirdWindow::on_pushButton_check_clicked()
{
        int mis = 0;
        QString str = thirdwindow->textEdit->toPlainText();
        QString text = thirdwindow->lineEdit->text();
        for (int i = 0; i < str.length(); i++){
            if (text[i] != str[i]){
                mis = mis + 1;
            }
        }
        int b = a;
        pause = true;
        int speed = text.length()/b*60;
        QString timetext = "Затраченое время: " + QString::number(b) + " секунды\n" +"Cкрость набора: "
                + QString::number(speed) + " с/м\n" + "Допущено ошибок: " + QString::number(mis) ;
        if (text == str){
            QMessageBox::information(this,"Результат","Все правильно.");
        } else {
            QMessageBox::information(this,"Результат","Допущены ошибки или текст набран не полностью.");
        }
            QMessageBox::information(this,"Время",timetext);
        thirdwindow->lineEdit->clear();
        thirdwindow->pushButton_start->setEnabled(true);
}

void ThirdWindow::on_pushButton_start_clicked()
{
    QString path;
    QString lvl1,lvl2,lvl3;
    QTimer* timer = new QTimer(this);
    t.setHMS(0,0,0);
    if (rand()%3+1 == 1){
        lvl1 = ":/res/levels/letters/firstLevel.txt";
    } else if (rand()%3+1 == 2){
        lvl1 = ":/res/levels/letters/secondLevel.txt";
    } else {
        lvl1 = ":/res/levels/letters/thirdLevel.txt";
    }
    if (rand()%3+1 == 1){
        lvl2 = ":/res/levels/words/firstLevel.txt";
    } else if (rand()%3+1 == 2){
        lvl2 = ":/res/levels/words/secondLevel.txt";
    } else {
        lvl2 = ":/res/levels/words/thirdLevel.txt";
    }    if (rand()%3+1 == 1){
        lvl3 = ":/res/levels/sentences/firstLevel.txt";
    } else if (rand()%3+1 == 2){
        lvl3 = ":/res/levels/sentences/secondLevel.txt";
    } else {
        lvl3 = ":/res/levels/sentences/thirdLevel.txt";
    }
    if (thirdwindow->radioButton_easy->isChecked()){
        path = lvl1 ;
        timer->start(1000);
    }
    if (thirdwindow->radioButton_normal->isChecked()){
        path = lvl2;
        timer->start(1000);
    }
    if (thirdwindow->radioButton_hard->isChecked()){
        path = lvl3 ;
        timer->start(1000);
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    QFile level(path);
          if(!level.open(QFile::ReadOnly | QFile::Text)){
             QMessageBox::information(this,"Error","Choose level");
             return;
        }
        QString buffer = level.readAll();
        thirdwindow->statusbar->showMessage(buffer);
        level.close();
        thirdwindow->textEdit->setText(buffer);
        thirdwindow->lineEdit->clear();
        thirdwindow->statusbar->showMessage(login);
        if (pause){
            timer->stop();
            a = 0;
        }
        thirdwindow->pushButton_start->setEnabled(false);
}

void ThirdWindow::on_pushButton_record_clicked()
{
    close();
    QMessageBox::information(this,"Результат","Перешло");
}

void ThirdWindow::onTimeout()
{
    thirdwindow->pushButton_check->setCheckable(true);;
        t = t.addSecs(1);
        a += 1;
    QString time_show = t.toString("mm:ss");
    thirdwindow->timertext->setText(time_show);
}
