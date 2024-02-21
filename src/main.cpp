#include <QApplication>

#include "baseWidget.h"

int main(int argv, char *argc[])
{
    QApplication qMainWindow(argv, argc);
    BaseWidget qMainWidget;

    qMainWidget.show();
    qMainWindow.exec();
    return 0;
}