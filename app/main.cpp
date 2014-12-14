#include "qrplot.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRPlot w;
    w.show();

    return a.exec();
}
