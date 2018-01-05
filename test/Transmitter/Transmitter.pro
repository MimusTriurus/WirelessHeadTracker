QT       += network

HEADERS       = glwidget.h \
                window.h \
                mainwindow.h \
                logo.h
SOURCES       = glwidget.cpp \
                main.cpp \
                window.cpp \
                mainwindow.cpp \
                logo.cpp

QT           += widgets

TARGET = Transmitter
# install
DESTDIR = ../../bin

INSTALLS += target

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
