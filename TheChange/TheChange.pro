TEMPLATE = app

QT += qml quick
CONFIG += c++11

CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

INCLUDEPATH += \
    $$PWD/App \
    $$PWD/App/Adapter \
    $$PWD/App/Common \
    $$PWD/App/Threads \

HEADERS += \
    App/DataLogger.h \
    App/QmlConstants.h \
    App/UIBridge.h \
    App/ScreenAdapter.h \
    App/DataEnum.h \
    App/DataManager.h \
    App/ThreadHandler.h \
    App/Threads/TimeSystemHandler.h \
    App/Threads/SettingsHandler.h \
    App/Common/Defines.h \
    App/Common/ScreenList.h \
    App/Adapter/ScreenAdapter.h \
    App/Adapter/TaskbarAdapter.h

SOURCES += \
    App/main.cpp \
    App/DataLogger.cpp \
    App/QmlConstants.cpp \
    App/UIBridge.cpp \
    App/DataManager.cpp \
    App/ThreadHandler.cpp \
    App/Threads/TimeSystemHandler.cpp \
    App/Threads/SettingsHandler.cpp \
    App/Common/123.cpp \
    App/Adapter/ScreenAdapter.cpp \
    App/Adapter/TaskbarAdapter.cpp

RESOURCES += qml.qrc \
    images.qrc

