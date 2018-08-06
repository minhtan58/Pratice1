#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QQmlApplicationEngine *qmlAppEngine, QObject *parent = nullptr);
    ~ScreenAdapter();
signals:

private:
    int m_screenId;
    QQuickItem* m_appContainer = nullptr;
    QQmlApplicationEngine *m_qmlAppEngine = nullptr;
public slots:
};

#endif // SCREENADAPTER_H
