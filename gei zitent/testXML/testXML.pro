#-------------------------------------------------
#
# Project created by QtCreator 2019-05-06T13:05:19
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testXML
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domxml.cpp

HEADERS  += mainwindow.h \
    domxml.h

FORMS    += mainwindow.ui

DISTFILES += \
    config.xml
