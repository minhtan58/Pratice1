#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <server.h>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Server *m_server;
    m_server= new Server;

    engine.rootContext()->setContextProperty("Server", m_server);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
