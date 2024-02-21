#ifndef _BASE_WIDGET_H
#define _BASE_WIDGET_H
#include <QWidget>
#include <QPushButton>
class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget *parent = nullptr);

private:
    QWidget m_qMainWidget;
    QPushButton m_qCloseButton;
    
    QSize getScreenSize();
    void basePlateInit(const int &width, const int &height);
    void pushButtonInit();
    void initSignal();

protected:
    void mouseMoveEvent(QMouseEvent* event);

};
#endif // !_BASE_WIDGET_H