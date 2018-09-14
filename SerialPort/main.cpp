#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "MySerialPort.h"
#include "ManagerEvent.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ManagerEvent managerEvent;
    managerEvent.initWindow();
    //MySerialPort m_SerialPort;
    //m_SerialPort.openSerialPort();

    return app.exec();
}
