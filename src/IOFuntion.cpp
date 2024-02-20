#include "IOFunction.h"

#include <QString>
#include <QFile>

QString readStyleSheet(const QString qsPath)
{
    QFile qFile(qsPath);
    qFile.open(QIODevice::ReadOnly);
    QString qsStyleText = qFile.readAll();
    qFile.close();
    return qsStyleText;
}