TEMPLATE = app

QT += core gui webenginewidgets webchannel

CONFIG += c++11
#QML debugging is enabled. Only use this in a safe environment.
CONFIG -= qml_debug

SOURCES += main.cpp \
    mainform.cpp \
    myform.cpp \
    webobject.cpp \
    bridge.cpp

RESOURCES += \
    img.qrc \
    web.qrc \
    js.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Default rules for deployment.
#include(deployment.pri)

DISTFILES += \
    Resources/开发说明

FORMS += \
    mainform.ui \
    myform.ui

HEADERS += \
    mainform.h \
    myform.h \
    webobject.h \
    bridge.h
