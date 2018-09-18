#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QObject *parent = 0);
    ~ScreenAdapter();

    void createScreen();
    int getCurrentScreen();
    void setScreenId(int screenId);
    void initAppData();

private:
    int m_screenId;
    QQmlApplicationEngine *m_qmlAppEngine = nullptr;
    QQuickItem* m_appContainer = nullptr;
    QObject* m_screenView = nullptr;

signals:

public slots:

};

#endif // SCREENADAPTER_H
