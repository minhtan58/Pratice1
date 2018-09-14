#include "UIBridge.h"
#include "eventid.h"
UIBridge::UIBridge(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(hmiEvent(int, QString)), parent, SLOT(hmiHandle(int,QString)));
}


QString UIBridge::getIPAddress() {
    return this->m_IPAddress;
}

void UIBridge::setIPAddress(QString newValue) {
    this->m_IPAddress = newValue;
}

QString UIBridge::getTime()
{
    currenttime = QTime::currentTime();
    return currenttime.toString("HH:mm:ss");
}
