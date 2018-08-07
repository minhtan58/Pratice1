#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>

#include "Screenlist.h"

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QQmlApplicationEngine *qmlAppEngine, QObject *parent = nullptr);
    ~ScreenAdapter();
    void createScreen();

signals:

private:
    int m_screenId;
    QQuickItem* m_appContainer = nullptr;
    QQmlApplicationEngine *m_qmlAppEngine = nullptr;
    QObject* m_screenView = nullptr;

public slots:
};

#endif // SCREENADAPTER_H
