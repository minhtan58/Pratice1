TEMPLATE = app

QT += qml quick serialport network
CONFIG += c++11

SOURCES += main.cpp \
    MySerialPort.cpp \
    ManagerEvent.cpp \
    UIBridge.cpp \
    MyTcpSocket.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    MySerialPort.h \
    ManagerEvent.h \
    UIBridge.h \
    Enum.h \
    MyTcpSocket.h
