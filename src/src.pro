include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = lib

TARGET = qrplot

SOURCES += \
    rsmreader.cpp \
    property.cpp \
    propertylist.cpp \
    summary.cpp \
    myclass.cpp \
    smreader.cpp
HEADERS += \
    rsmreader.h \
    property.h \
    propertylist.h \
    summary.h \
    myclass.h \
    smreader.h
