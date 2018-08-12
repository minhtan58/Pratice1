#ifndef TASKBARADAPTERR_H
#define TASKBARADAPTERR_H

#include <QObject>
#include <QQuickItem>

class TaskbarAdapter : public QObject
{
    Q_OBJECT
public:
    explicit TaskbarAdapter(QQuickItem *coontainer, QObject *parent = nullptr);
    void initAppData();

private:
    QQuickItem *m_taskbarContainer = nullptr;
    QObject *m_taskbarView = nullptr;
signals:

public slots:
    void updateAppData(int dpid);
};

#endif // TASKBARADAPTERR_H
