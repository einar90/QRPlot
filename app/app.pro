#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T15:00:14
#
#-------------------------------------------------
include(../defaults.pri)

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        qrplot.cpp \
    qcustomplot.cpp \
    plotline.cpp \
    graph.cpp \
    propertyinfo.cpp \
    propertyinfolist.cpp

HEADERS  += qrplot.h \
    qcustomplot.h \
    plotline.h \
    graph.h \
    propertyinfo.h \
    propertyinfolist.h

FORMS    += qrplot.ui

LIBS += -L../src -lqrplot

RESOURCES += \
    icons.qrc
