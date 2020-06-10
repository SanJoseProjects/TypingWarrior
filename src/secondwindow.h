#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QFile>
#include <QItemDelegate>
#include <QMainWindow>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit SecondWindow(QMainWindow* parent = nullptr);
    ~SecondWindow();

private slots:

    void on_pushButton_Submit_clicked();

    void on_pushButton_DeleteRow_clicked();

    void on_pushButton_ClearTable_clicked();

private:
    Ui::SecondWindow* secondwindow;
    int i;
    QSqlDatabase db;
    QSqlTableModel* model;
};

#endif // SECONDWINDOW_H
