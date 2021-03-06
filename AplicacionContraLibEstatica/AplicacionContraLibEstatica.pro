QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/release/ -lBibEstatica
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/debug/ -lBibEstatica
else:unix: LIBS += -L$$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/ -lBibEstatica

INCLUDEPATH += $$PWD/../BibEstatica
DEPENDPATH += $$PWD/../BibEstatica

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/release/libBibEstatica.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/debug/libBibEstatica.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/release/BibEstatica.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/debug/BibEstatica.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-BibEstatica-Desktop_Qt_5_11_1_GCC_64bit-Release/libBibEstatica.a
