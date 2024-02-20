#ifndef _BASE_WIDGET_H
#define _BASE_WIDGET_H
#include <QWidget>

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget *parent = nullptr);

private:
    void basePlateInit();
    QWidget m_qMainWidget;
};
#endif // !_BASE_WIDGET_H