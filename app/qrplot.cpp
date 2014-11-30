#include "qrplot.h"
#include "ui_qrplot.h"

QRPlot::QRPlot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPlot)
{
    ui->setupUi(this);
}

QRPlot::~QRPlot()
{
    delete ui;
}
