#ifndef SETTINGSHANDLER_H
#define SETTINGSHANDLER_H

#include <QObject>

class SettingsHandler : public QObject
{
    Q_OBJECT
public:
    explicit SettingsHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SETTINGSHANDLER_H