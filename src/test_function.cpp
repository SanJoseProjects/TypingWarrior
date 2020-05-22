#include "test_function.h"
#include "thirdwindow.h"
#include <QTest>
test_function::test_function()
{

}

test_function::~test_function()
{

}

void test_function::speed_measurement()
{
   ThirdWindow test;
   QCOMPARE(test.speed_measurement(5, "dadaadarwqerwqf"), 180);
   QCOMPARE(test.speed_measurement(5, ""), 0);
   QCOMPARE(test.speed_measurement(30, "dgfdaadarwqrwqp"), 30);
   QCOMPARE(test.speed_measurement(15, "mdpaegjyqerfgfv"), 60);

}
void test_function::text_verification()
{
    ThirdWindow test;
    QCOMPARE(test.text_verification("hhhhhda","hhhhhda"), 0);
    QCOMPARE(test.text_verification("asdf","a sdf"), 4);
    QCOMPARE(test.text_verification("edge",""), 4);
    QCOMPARE(test.text_verification("asde","as"), 2);
    QCOMPARE(test.text_verification("sadfsae","safdsae"), 2);
    QCOMPARE(test.text_verification("dsaasa","dsaysa"), 1);
    QCOMPARE(test.text_verification("fdsfds","fdsfdsgg"), 2);
}
void test_function::open_file()
{
    ThirdWindow test;
    QCOMPARE(test.open_file(":/res/levels/test/test.txt"), "Function is working.");
    QCOMPARE(test.open_file(":/res/levels/test/test1.txt"), "ERROR FILE IS NOT CHOSEN");
}


