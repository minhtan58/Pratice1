#include "TimeSystemHandler.h"

#define SETDPDATA(DPID, VALUE)  DataManager::getInstance()->setData(DPID, VALUE)

TimeSystemHandler::TimeSystemHandler(QObject *parent)
    : QObject(parent)
{}

void TimeSystemHandler::updateTimeSystem(){
    SETDPDATA(DataEnum::DP_SYS_DATE, QDateTime::currentDateTime().toString("dd/MM/yyyy"));
    SETDPDATA(DataEnum::DP_SYS_TIME, QDateTime::currentDateTime().toString("hh:mm"));

    SETDPDATA(DataEnum::DP_SYS_TIME_HOUR, QDateTime::currentDateTime().toString("HH"));     //hour always 24h format
    SETDPDATA(DataEnum::DP_SYS_TIME_MINUTES, QDateTime::currentDateTime().toString("mm"));

    SETDPDATA(DataEnum::DP_SYS_DATE_YEAR, QDateTime::currentDateTime().toString("yyyy"));
    SETDPDATA(DataEnum::DP_SYS_DATE_MONTH, QDateTime::currentDateTime().toString("MM"));
    SETDPDATA(DataEnum::DP_SYS_DATE_DAY, QDateTime::currentDateTime().toString("dd"));
}

void TimeSystemHandler::eventHandler(QString objectName, int eventID, QString param){
    QStringList params = param.split(",");
    Q_UNUSED(objectName)
    switch (eventID) {
    case DataEnum::HMI_SWITCH_UPDATE_TIME_AUTOMATIC:{
        SETDPDATA(DataEnum::DP_SYS_SETTINGS_TIME_AUTOMATIC_UPDATE, QString::number(1 - param.toUInt()));

        break;
    }
    default:
        break;
    }
}
