#ifndef MANAGERDATA_H
#define MANAGERDATA_H

#include <QObject>
#include <QQuickItem>
#include <QMap>
#include <QHash>
#include <QList>
#include <QMutex>

#include "Enum.h"

class ManagerData : public QObject
{
    Q_OBJECT
public:
    explicit ManagerData(QObject *parent = 0);
    static ManagerData* getInstance();

    QString getData(int dpId);
    void setData(int dpid, QString value);
    QString getDataName(int dpId);

private:
    static ManagerData *m_managerData;
    QHash<int, QString> m_datapool;
    QHash<int, QString> m_dpName;
    QMutex mutex;

    void initData();

signals:
    void dataChanged(int dpid);

public slots:
};

#endif // MANAGERDATA_H
