#include "baseWidget.h"

#include <QDir>
#include <QScreen>
#include <QGuiApplication>
#include <QDrag>
#include <QDebug>
#include <QString>
#include <QFontDatabase>

#include "IOFunction.h"
#pragma execution_character_set("utf-8")
BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{
    basePlateInit(500, 500);
    pushButtonInit();
    initSignal();
}

QSize BaseWidget::getScreenSize()
{
    QScreen *qScreen = QGuiApplication::primaryScreen();
    QSize qSize = qScreen->size();
    return qSize;
}

void BaseWidget::basePlateInit(const int &width, const int &height)
{
    m_qMainWidget.setParent(this);
    this->setWindowFlags(Qt::FramelessWindowHint);          // 无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true); // 透明底
    this->resize(width, height);
    m_qMainWidget.resize(width, height);
    QString qsStyleSheetPath =
        QDir::currentPath() + "\\styleSheet\\widgetDefaultStyle.qss";
    m_qMainWidget.setStyleSheet(readStyleSheet(qsStyleSheetPath));
    QSize qSize = getScreenSize();
    this->move(qSize.width() - width, 0);
}

void BaseWidget::pushButtonInit()
{
    QSize qmainWidgetSize = m_qMainWidget.size();
    m_qCloseButton.setParent(&m_qMainWidget);
    m_qCloseButton.setGeometry(qmainWidgetSize.width() - 50, 10, 30, 30);
    m_qCloseButton.setText("关");
    m_qCloseButton.setObjectName("mainCloseButton");
    int iFontId = QFontDatabase::addApplicationFont(
        QDir::currentPath() + R"(\SourceHanSansSC-Regular.otf)");
    QStringList fontList = QFontDatabase::applicationFontFamilies(iFontId);
    QFont qsFont;
    qsFont.setFamily(fontList[0]);
    m_qCloseButton.setFont(qsFont);
}

void BaseWidget::initSignal()
{
    QObject::connect(
        &m_qCloseButton, &QPushButton::clicked,
        [&]()
        {
            qDebug() << "close";
            this->close();
        });
}

void BaseWidget::mouseMoveEvent(QMouseEvent *event)
{
    QDrag drag(this);
}