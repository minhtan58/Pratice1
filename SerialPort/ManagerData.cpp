#include "ManagerData.h"

#define INITDATA(param) \
    m_datapool.insert((int)param, (QString)""); \
    m_dpName.insert((int)param, ((QString)#param).mid(10))

ManagerData::ManagerData(QObject *parent) : QObject(parent)
{
    initData();
    //DbManager::getInstance();
}

ManagerData *ManagerData::getInstance()
{
    if(m_managerData == nullptr) {
        m_managerData = new ManagerData();
    }
    return m_managerData;
}

QString ManagerData::getData(int dpId)
{
    if(m_datapool.contains(dpId)) {
        return m_datapool.value(dpId);
    }
    return "";
}

void ManagerData::setData(int dpid, QString value)
{
    if(m_datapool.contains(dpid)) {
        if (getData(dpid) != value) {
            mutex.lock();
            m_datapool[dpid] = value;
            mutex.unlock();
            emit dataChanged(dpid);
//            DLOG(" %s : %s", getDataName(dpid).toStdString().data(), value.toStdString().data());
            return;
        }
    } else {
        qDebug() << ("DPID: %d Incorrect", dpid);
    }
}

QString ManagerData::getDataName(int dpId)
{
    if(m_dpName.contains(dpId)) {
        return m_dpName.value(dpId);
    }
    return "";
}

void ManagerData::initData()
{
    INITDATA(EnumID::DP_TIME);
    INITDATA(EnumID::DP_DATE);
    INITDATA(EnumID::DP_HOUR);
    INITDATA(EnumID::DP_MINUTES);
    INITDATA(EnumID::DP_DAY);
    INITDATA(EnumID::DP_MONTH);
    INITDATA(EnumID::DP_YEAR);
    INITDATA(EnumID::DP_FROM_PORTCOM);
    INITDATA(EnumID::DP_FROM_NETWORK);
}
