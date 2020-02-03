#-------------------------------------------------
#
# Project created by QtCreator 2019-06-17T16:44:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testTcpServer
TEMPLATE = app


SOURCES += main.cpp\
    server.cpp \
    tcpclientsocket.cpp \
    tcpserver.cpp

HEADERS  += \
    server.h \
    tcpclientsocket.h \
    tcpserver.h

FORMS    += \
    tcpserver.ui
