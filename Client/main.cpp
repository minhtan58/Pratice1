#include <QGuiApplication>
#include "WinDow.h"
#include "eventid.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<EventID>("EventID", 1, 0, "EventID");
    //qmlRegisterType<Client>("Client",1,0,"Client");
    WinDow window;
    return app.exec();
}
