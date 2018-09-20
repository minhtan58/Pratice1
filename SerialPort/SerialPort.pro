TEMPLATE = app

QT += qml quick serialport network
CONFIG += c++11

CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

INCLUDEPATH += \
    $$PWD/Common \
    $$PWD/Connection \
    $$PWD/Threads \

SOURCES += main.cpp \
    ManagerEvent.cpp \
    UIBridge.cpp \
    ManagerData.cpp \
    ScreenAdapter.cpp \
    Connection/MySerialPort.cpp \
    Connection/MyTcpSocket.cpp \
    Threads/TimeHandler.cpp \
    Threads/SerialPortHandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ManagerEvent.h \
    UIBridge.h \
    ManagerData.h \
    ScreenAdapter.h \
    Common/Defines.h \
    Common/Enum.h \
    Connection/MySerialPort.h \
    Connection/MyTcpSocket.h \
    Threads/TimeHandler.h \
    Threads/SerialPortHandler.h
