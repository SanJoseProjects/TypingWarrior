QT += testlib
QT += core gui sql widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../src/thirdwindow.cpp \
    main.cpp \
    test_function.cpp

HEADERS += \
    ../src/thirdwindow.h \
    test_function.h

FORMS += \
    ../src/thirdwindow.ui

RESOURCES += \
    res.qrc
