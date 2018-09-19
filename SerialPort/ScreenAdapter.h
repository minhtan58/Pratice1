#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include "Enum.h"
#include "Defines.h"

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QObject *container, QObject *parent = 0);
    ~ScreenAdapter();

    void createScreen();
    int getCurrentScreen();
    void setScreenId(int screenId);
    void initAppData();
    void updateAppdata(int dpid);

private:
    int m_screenId;
    QObject* m_screenContainer = nullptr;
    QObject* m_screenView = nullptr;

signals:

public slots:

};

#endif // SCREENADAPTER_H
