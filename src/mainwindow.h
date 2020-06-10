#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"
#include "thirdwindow.h"
#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_start_clicked();

    void okEnabled();

    void on_pushButton_record_clicked();

    void closeEvent(QCloseEvent* event);

private:
    Ui::MainWindow* firstwindow;
    SecondWindow* secondwindow;
    ThirdWindow* thirdwindow;
    QString login;
};
#endif // MAINWINDOW_H
