#ifndef TEST_FUNCTION_H
#define TEST_FUNCTION_H

#include <QObject>

class test_function : public QObject
{
    Q_OBJECT

public:
    test_function();
    ~test_function();

private slots:
    void speed_measurement();
    void text_verification();
    void open_file();

};



#endif // TEST_FUNCTION_H
