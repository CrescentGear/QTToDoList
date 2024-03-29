#include "baseWidget.h"
#include <QDir>

#include "IOFunction.h"

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{
    basePlateInit();
}

void BaseWidget::basePlateInit()
{
    m_qMainWidget.setParent(this);
    this->setWindowFlags(Qt::FramelessWindowHint);          // 无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true); // 透明底
    this->resize(500, 500);
    m_qMainWidget.resize(500, 500);
    QString qsStyleSheetPath =
        QDir::currentPath() + "\\styleSheet\\widgetDefaultStyle.qss";
    m_qMainWidget.setStyleSheet(readStyleSheet(qsStyleSheetPath));
}