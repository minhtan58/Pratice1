TEMPLATE = app

QT += qml quick serialport network
CONFIG += c++11

INCLUDEPATH += \
    $$PWD/Common \
    $$PWD/Connection \
    $$PWD/Threads \

SOURCES += main.cpp \
    MySerialPort.cpp \
    ManagerEvent.cpp \
    UIBridge.cpp \
    MyTcpSocket.cpp \
    ManagerData.cpp \
    ScreenAdapter.cpp \
    Connection/MySerialPort.cpp \
    Connection/MyTcpSocket.cpp \
    Threads/TimeHandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ManagerEvent.h \
    UIBridge.h \
    Enum.h \
    MyTcpSocket.h \
    TimeHandler.h \
    ManagerData.h \
    ScreenAdapter.h \
    Common/Defines.h \
    Common/Enum.h \
    Connection/MySerialPort.h \
    Connection/MyTcpSocket.h \
    Threads/TimeHandler.h
