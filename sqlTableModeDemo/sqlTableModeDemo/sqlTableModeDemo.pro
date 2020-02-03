#-------------------------------------------------
#
# Project created by QtCreator 2017-11-23T09:38:37
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlTableModeDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysqltablemodel.cpp

HEADERS  += mainwindow.h \
    mysqltablemodel.h

FORMS    += mainwindow.ui
