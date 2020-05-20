#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include "thirdwindow.h"
#include <QMessageBox>
#include <QString>
#include <QRegExpValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_start_clicked();

    void okEnabled();

private:
    Ui::MainWindow *firstwindow;
    SecondWindow *secondwindow;
    ThirdWindow *thirdwindow;
};
#endif // MAINWINDOW_H
