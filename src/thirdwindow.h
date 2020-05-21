#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <QCloseEvent>
namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_pushButton_record_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_check_clicked();

    void onTimeout();

    void closeEvent(QCloseEvent *event);

private:
    Ui::ThirdWindow *thirdwindow;
};

#endif // THIRDWINDOW_H
