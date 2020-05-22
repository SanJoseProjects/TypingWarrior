#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit SecondWindow(QWidget *parent = nullptr);
  ~SecondWindow();

private slots:

private:
  Ui::SecondWindow *secondwindow;
  int i;
};

#endif // SECONDWINDOW_H
