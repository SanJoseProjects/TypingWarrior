#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H
#include <QMainWindow>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void onTimeout();

private:
    Ui::ThirdWindow *thirdwindow;
};

#endif // THIRDWINDOW_H
