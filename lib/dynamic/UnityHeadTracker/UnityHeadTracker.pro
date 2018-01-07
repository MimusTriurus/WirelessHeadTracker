#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T17:42:38
#
#-------------------------------------------------

QT       += network

TARGET = UnityHeadTracker
TEMPLATE = lib
CONFIG += c++11

#DESTDIR = ../../../bin

DEFINES += UNITYHEADTRACKER_LIBRARY

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
        UnityHeadTracker.cpp \
    HeadTracker.cpp

HEADERS += \
        UnityHeadTracker.h \
    HeadTracker.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
### Converter ##################################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../static/Converter/release/ -lConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../static/Converter/debug/ -lConverter
else:unix:!macx: LIBS += -L$$OUT_PWD/../../static/Converter/ -lConverter

INCLUDEPATH += $$PWD/../../static/Converter
DEPENDPATH += $$PWD/../../static/Converter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/Converter/release/libConverter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/Converter/debug/libConverter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/Converter/release/Converter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/Converter/debug/Converter.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../static/Converter/libConverter.a
### DataProvider ###############################################################
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../static/DataProvider/release/ -lDataProvider
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../static/DataProvider/debug/ -lDataProvider
else:unix:!macx: LIBS += -L$$OUT_PWD/../../static/DataProvider/ -lDataProvider

INCLUDEPATH += $$PWD/../../static/DataProvider
DEPENDPATH += $$PWD/../../static/DataProvider

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/DataProvider/release/libDataProvider.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/DataProvider/debug/libDataProvider.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/DataProvider/release/DataProvider.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../static/DataProvider/debug/DataProvider.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../static/DataProvider/libDataProvider.a
