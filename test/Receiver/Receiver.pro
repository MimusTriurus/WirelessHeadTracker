QT += network

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

TARGET = Receiver
# install
DESTDIR = ../../bin

INSTALLS += target

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/DataProvider/release/ -lDataProvider
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/DataProvider/debug/ -lDataProvider
else:unix:!macx: LIBS += -L$$OUT_PWD/../../lib/static/DataProvider/ -lDataProvider

INCLUDEPATH += $$PWD/../../lib/static/DataProvider
DEPENDPATH += $$PWD/../../lib/static/DataProvider

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataProvider/release/libDataProvider.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataProvider/debug/libDataProvider.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataProvider/release/DataProvider.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataProvider/debug/DataProvider.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/DataProvider/libDataProvider.a
