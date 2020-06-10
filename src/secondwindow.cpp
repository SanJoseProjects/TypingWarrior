#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QMainWindow* parent)
    : QMainWindow(parent), secondwindow(new Ui::SecondWindow)
{
    secondwindow->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Scoreboard.db");
    db.open();
    model = new QSqlTableModel(this, db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("Board");
    model->select();
    secondwindow->tableView->setModel(model);
    QHeaderView* header = secondwindow->tableView->horizontalHeader();
    header->setStretchLastSection(true);
    secondwindow->tableView->setEditTriggers(QTableView::NoEditTriggers);
}

SecondWindow::~SecondWindow()
{
    delete secondwindow;
}

void SecondWindow::on_pushButton_Submit_clicked()
{
    model->submitAll();
}

void SecondWindow::on_pushButton_DeleteRow_clicked()
{
    int selectedRow = secondwindow->tableView->currentIndex().row();
    if (selectedRow >= 0)
        model->removeRow(selectedRow);
}

void SecondWindow::on_pushButton_ClearTable_clicked()
{
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM Board");
    query.next();
    int rows = query.value(0).toInt();
    for (int i = 0; i < rows; i++) {
        model->removeRow(i);
    }
}
