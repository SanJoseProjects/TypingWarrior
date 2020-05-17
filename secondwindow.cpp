#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    seconswindow(new Ui::SecondWindow)
{
    seconswindow->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete seconswindow;
}
void SecondWindow::on_pushButton_clicked()
{
    thirdwindow = new ThirdWindow(this);
    thirdwindow->setWindowTitle ("TypingWarrior");
    thirdwindow->show();
    if(seconswindow->radioButton->isChecked()){

    }
}
