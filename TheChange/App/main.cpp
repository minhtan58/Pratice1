#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "DataLogger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/resources/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;
    DataLogger logger;
    logger.initDatalogger();
    return app.exec();
}
