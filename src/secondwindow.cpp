#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    secondwindow(new Ui::SecondWindow)
{
    secondwindow->setupUi(this);
    QFile high_score_table(":/res/levels/letters/Score.txt");
        if(!high_score_table.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::information(this,"Error","File not found");
            return;
        }
        QString buffer = high_score_table.readAll();
        high_score_table.close();
        QString record[33];
        for (int i=0; ((15<i)&(i<=30)); i++){
            record[i] = " ";
        }
        secondwindow->textEdit->setText(buffer);
        secondwindow->textEdit->setReadOnly(true);
}

SecondWindow::~SecondWindow()
{
    delete secondwindow;
}
