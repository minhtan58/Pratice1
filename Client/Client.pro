TEMPLATE = app

QT += qml quick
CONFIG += c++11

QT += network



SOURCES += main.cpp \
    WinDow.cpp \
    UIBridge.cpp \
    client.cpp \
    eventid.cpp \
    status.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    WinDow.h \
    UIBridge.h \
    eventid.h \
    eventid.h \
    client.h \
    status.h
