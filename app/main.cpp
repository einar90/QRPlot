#include "qrplot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRPlot w;
    w.show();

    return a.exec();
}
