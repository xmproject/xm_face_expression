#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T19:19:40
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xm_face_qt
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    xm_face.h

FORMS    += widget.ui

RESOURCES += \
    xm_face.qrc
