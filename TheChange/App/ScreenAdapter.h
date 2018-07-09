#ifndef SCREENADAPTER_H
#define SCREENADAPTER_H

#include <QObject>
#include <QQuickItem>

class ScreenAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ScreenAdapter(QObject *parent = 0);
    ~ScreenAdapter();
signals:

private:
    int m_screenId;
    QQuickItem* m_appContainer = nullptr;
public slots:
};

#endif // SCREENADAPTER_H
