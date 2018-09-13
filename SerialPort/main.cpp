#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "MySerialPort.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    MySerialPort m_SerialPort;
    m_SerialPort.openSerialPort();

    return app.exec();
}
