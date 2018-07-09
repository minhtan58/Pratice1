#include "ScreenAdapter.h"

ScreenAdapter::ScreenAdapter(int screenId, QQuickItem *container, QObject *parent)
    : QObject(parent)
    , m_screenId(screenId)
    , m_appContainer(container)
{}

ScreenAdapter::~ScreenAdapter()
{}
