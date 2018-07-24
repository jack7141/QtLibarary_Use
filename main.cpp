#include "mainwindow.h"
#include <QApplication>
#include <QtGui>//?
#include <QLibrary>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLibrary library("C:\\work\\QRO_ABS\\Library\\build-testQLib-Desktop_Qt_5_10_1_MinGW_32bit-Debug\\debug\\testQLib.dll");
    if (!library.load())
        qDebug() << library.errorString();
    if (library.load())
        qDebug() << "library loaded";

    typedef QWidget *(*CreateWidgetFunction)();
    CreateWidgetFunction cwf = (CreateWidgetFunction)library.resolve("createWidget1");
    if (cwf){
        QWidget *widget = cwf();
        if (widget) widget->show();
    } else {
        qDebug() << "Could not show widget from the loaded library";
    }
    return a.exec();
}
