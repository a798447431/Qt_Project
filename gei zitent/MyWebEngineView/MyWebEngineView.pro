CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(webengineviewplugin)
TEMPLATE    = lib

HEADERS     = webengineviewplugin.h
SOURCES     = webengineviewplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}
QT += webenginewidgets
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

#include(webengineview.pri)
