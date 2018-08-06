#include "DataManager.h"

#define INITDATA(param) \
    m_datapool.insert((int)param, (QString)""); \
    m_dpName.insert((int)param, ((QString)#param).mid(10))

DataManager::DataManager(QObject *parent) : QObject(parent)
{
    initData();
}

DataManager *DataManager::getInstance(){
    if(m_dataManager == nullptr)
        m_dataManager = new DataManager();
    return m_dataManager;
}

QString DataManager::getData(int dpID){
    if(m_datapool.contains(dpID)){
        return m_datapool.value(dpID);
    }
    //return "";
}


void DataManager::setData(int dpID, QString value){
    if(m_datapool.contains(dpID)){
        if(getData(dpID) != value){
            mutex.lock();
            m_datapool[dpID] = value;
            mutex.unlock();
            emit dataChanged(dpID);
            return;
        }
    }
    else{
        HLOG("DPID: %d Incorrect", dpID);
    }
}

void DataManager::initData(){
    INITDATA(DataEnum::DP_PPM_AIR_O2);
    INITDATA(DataEnum::DP_PPM_AIR_CO);
    INITDATA(DataEnum::DP_PPM_AIR_NO);
    INITDATA(DataEnum::DP_PPM_AIR_NOX);
    INITDATA(DataEnum::DP_PPM_AIR_SO2);
}
