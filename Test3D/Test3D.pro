TEMPLATE = app
CONFIG += console c++17

INCLUDEPATH += C:/Users/Ricardo/Documents/Projet/projetIrrLicht/irrlicht/include
LIBS += -l Irrlicht
SOURCES += \
        MyInputReceiver.cpp \
        actionManager.cpp \
        main.cpp \
        mymesh.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/ -lIrrlicht
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/ -lIrrlichtd
else:unix: LIBS += -L$$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/ -lIrrlicht

INCLUDEPATH += $$PWD/../../projetIrrLicht/irrlicht/include
DEPENDPATH += $$PWD/../../projetIrrLicht/irrlicht/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/libIrrlicht.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/libIrrlichtd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/Irrlicht.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/Irrlichtd.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../projetIrrLicht/irrlicht/lib/Win32-gcc/libIrrlicht.a

HEADERS += \
    MyInputReceiver.h \
    actionManager.h \
    mymesh.h

QT += widgets
