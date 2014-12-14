include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

TEMPLATE = app

SOURCES += main.cpp

LIBS += -lunittest++ -L../src -lqrplot

OTHER_FILES += \
    data/10x10.RSM
    data/10x10.SMSPEC
    data/10x10.UNSMRY

DESTDIR = $$PWD
