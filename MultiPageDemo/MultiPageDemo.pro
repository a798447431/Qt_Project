#-------------------------------------------------
#
# Project created by QtCreator 2011-10-30T12:08:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = MultiPageDemo
TEMPLATE = app

DESTDIR = bin
MOC_DIR = temp
OBJECTS_DIR = temp
UI_DIR = temp

SOURCES += main.cpp\
        Widget.cpp \
    PageWidget.cpp \
    PagingWidget.cpp \
    TableWidgetForm.cpp

HEADERS  += Widget.h \
    PageWidget.h \
    PagingWidget.h \
    TableWidgetForm.h

FORMS    += Widget.ui \
    PageWidget.ui \
    PagingWidget.ui \
    TableWidgetForm.ui

DISTFILES +=

RESOURCES += \
    qrc.qrc



