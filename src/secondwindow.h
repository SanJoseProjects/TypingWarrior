#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:

private:
    Ui::SecondWindow *secondwindow;
};

#endif // SECONDWINDOW_H
