#include "ScreenAdapter.h"

ScreenAdapter::ScreenAdapter(QQmlApplicationEngine *qmlAppEngine, QObject *parent)
    : QObject(parent)
    , m_qmlAppEngine(qmlAppEngine)
    , m_screenId(-1)
{}

ScreenAdapter::~ScreenAdapter()
{}
