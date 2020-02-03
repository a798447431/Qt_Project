#-------------------------------------------------
#
# Project created by QtCreator 2019-05-08T11:02:32
#
#------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testMysql
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
#指定动态库
#LIBS+=-L"/root/project/build-testMysql-Desktop_Qt_5_5_1_GCC_32bit-Debug"
#编译目标代码时指定的动态库搜索路径
#QMAKE_RPATHDIR+=/usr/local/lib

#unix:!macx: LIBS += -L$$PWD/../build-testMysql-Desktop_Qt_5_5_1_GCC_32bit-Debug/ -lqsqlmysql

#INCLUDEPATH += $$PWD/../build-testMysql-Desktop_Qt_5_5_1_GCC_32bit-Debug
#DEPENDPATH += $$PWD/../build-testMysql-Desktop_Qt_5_5_1_GCC_32bit-Debug
