#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QMutex>
#include <QMap>
#include <QHash>
#include <QList>

#include "DataEnum.h"
#include "Defines.h"

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    static DataManager *getInstance();
    QString getData(int dpID);
    void setData(int dpID, QString value);
private:
    static DataManager *m_dataManager;
    QHash<int, QString> m_datapool;
    QHash<int, QString> m_dpName;
    QMutex mutex;
    void initData();
signals:
    void dataChanged(int dpid);
public slots:
};

#endif // DATAMANAGER_H
