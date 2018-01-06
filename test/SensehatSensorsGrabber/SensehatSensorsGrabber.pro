#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T20:57:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SensehatSensorsGrabber
TEMPLATE = app

CONFIG += c++11

DESTDIR = ../../bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui

### Converter ##################################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/Converter/release/ -lConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/Converter/debug/ -lConverter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/Converter/ -lConverter

INCLUDEPATH += $$PWD/../../lib/static/Converter
DEPENDPATH += $$PWD/../../lib/static/Converter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/release/libConverter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/debug/libConverter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/release/Converter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/debug/Converter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/Converter/libConverter.a
### DataTransmitter ############################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/DataTransmitter/release/ -lDataTransmitter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/DataTransmitter/debug/ -lDataTransmitter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/DataTransmitter/ -lDataTransmitter

INCLUDEPATH += $$PWD/../../lib/static/DataTransmitter
DEPENDPATH += $$PWD/../../lib/static/DataTransmitter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataTransmitter/release/libDataTransmitter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataTransmitter/debug/libDataTransmitter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataTransmitter/release/DataTransmitter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataTransmitter/debug/DataTransmitter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataTransmitter/libDataTransmitter.a
### SensorsDataGetter ##########################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/SensorsDataGetter/release/ -lSensorsDataGetter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/SensorsDataGetter/debug/ -lSensorsDataGetter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/SensorsDataGetter/ -lSensorsDataGetter

INCLUDEPATH += $$PWD/../../lib/static/SensorsDataGetter
DEPENDPATH += $$PWD/../../lib/static/SensorsDataGetter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/SensorsDataGetter/release/libSensorsDataGetter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/SensorsDataGetter/debug/libSensorsDataGetter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/SensorsDataGetter/release/SensorsDataGetter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/SensorsDataGetter/debug/SensorsDataGetter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/SensorsDataGetter/libSensorsDataGetter.a
### AHRS #######################################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/AHRS/release/ -lAHRS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/AHRS/debug/ -lAHRS
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/AHRS/ -lAHRS

INCLUDEPATH += $$PWD/../../lib/static/AHRS
DEPENDPATH += $$PWD/../../lib/static/AHRS

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/AHRS/release/libAHRS.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/AHRS/debug/libAHRS.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/AHRS/release/AHRS.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/AHRS/debug/AHRS.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/AHRS/libAHRS.a
### RTIMU ######################################################################
unix:!macx: LIBS += -L$$PWD/../../lib/static/SensorsDataGetter/lib/ -lRTIMULib

INCLUDEPATH += $$PWD/../../lib/static/SensorsDataGetter/include
DEPENDPATH += $$PWD/../../lib/static/SensorsDataGetter/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../lib/static/SensorsDataGetter/lib/libRTIMULib.a
