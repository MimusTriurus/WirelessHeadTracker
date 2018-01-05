#-------------------------------------------------
#
# Project created by QtCreator 2017-10-08T11:27:53
#
#-------------------------------------------------

QT       -= gui

TARGET = SensorsDataGetter
TEMPLATE = lib
CONFIG += staticlib

MOC_DIR = moc
OBJECTS_DIR = obj

DEFINES += HEADTRACKER_LIBRARY

SOURCES += \
    RtimuSensorsGetter.cpp

HEADERS += \
    RtimuSensorsGetter.h \
    IOrientationGetter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix: LIBS += -L$$PWD/lib/ -lRTIMULib

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix: PRE_TARGETDEPS += $$PWD/lib/libRTIMULib.a
