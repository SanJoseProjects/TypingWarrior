#include <iostream>
#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <QTimer>
#include <QTime>
#include <QMessageBox>
    QString login;
ThirdWindow::ThirdWindow(QWidget *parent) :
    QMainWindow(parent),
    thirdwindow(new Ui::ThirdWindow)
{
    thirdwindow->setupUi(this);
    QTimer* timer = new QTimer(this);
    timer->start(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    thirdwindow->textEdit->setReadOnly(true);
}

ThirdWindow::~ThirdWindow()
{
    delete thirdwindow;
}
char checking_text[] = {"— Ах, не говорите мне про Австрию! Я ничего не понимаю, может быть, но Австрия никогда не хотела и не хочет войны. Она предает нас. Россия одна должна быть спасительницей Европы. Наш благодетель знает свое высокое призвание и будет верен ему. Вот одно, во что я верю. Нашему доброму и чудному государю предстоит величайшая роль в мире, и он так добродетелен и хорош, что Бог не оставит его, и он исполнит свое призвание задавить гидру революции, которая теперь еще ужаснее в лице этого убийцы и злодея. Мы одни должны искупить кровь праведника. На кого нам надеяться, я вас спрашиваю?.. Англия с своим коммерческим духом не поймет и не может понять всю высоту души императора Александра. Она отказалась очистить Мальту. Она хочет видеть, ищет заднюю мысль наших действий. Что они сказали Новосильцеву? Ничего. Они не поняли, они не могли понять самоотвержения нашего императора, который ничего не хочет для себя и все хочет для блага мира. И что они обещали? Ничего. И что обещали, и того не будет! Пруссия уже объявила, что Бонапарте непобедим и что вся Европа ничего не может против него... И я не верю ни в одном слове ни Гарденбергу, ни Гаугвицу. Cette fameuse neutralité prussienne, ce n'est qu'un piège 9. Я верю в одного Бога и в высокую судьбу нашего милого императора. Он спасет Европу!.. — Она вдруг остановилась с улыбкой насмешки над своею горячностью."};
void ThirdWindow::on_pushButton_clicked()
{
    QString text = thirdwindow->lineEdit->text();
    if (text == checking_text){
        QMessageBox::information(this,"Результат","Все правильно");
    } else {
        QMessageBox::information(this,"Результат","Ты тупой");
    }
    hide();
    thirdwindow->lineEdit->clear();
}

void ThirdWindow::on_pushButton_2_clicked()
{
    thirdwindow->textEdit->setText(checking_text);
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
    thirdwindow->timertext->setText(QTime::currentTime().toString());
}
