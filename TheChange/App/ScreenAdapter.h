#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>

#include "Screenlist.h"
#include "UIBridge.h"

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QQmlApplicationEngine *qmlAppEngine, QObject *parent = nullptr);
    ~ScreenAdapter();
    void createScreen();
    void initAppData();
    void setScreenId(int screenId);
    void getCurrentScreen();
private:
    int m_screenId;
    QQuickItem* m_appContainer = nullptr;
    QQmlApplicationEngine *m_qmlAppEngine = nullptr;
    QObject* m_screenView = nullptr;
signals:

public slots:
    void eventHandler(QString objectName, int eventId, QString param);

};

#endif // SCREENADAPTER_H
