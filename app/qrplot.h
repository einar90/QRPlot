#ifndef QRPLOT_H
#define QRPLOT_H

#include <QMainWindow>

namespace Ui {
class QRPlot;
}

class QRPlot : public QMainWindow
{
    Q_OBJECT

public:
    explicit QRPlot(QWidget *parent = 0);
    ~QRPlot();

private:
    Ui::QRPlot *ui;
};

#endif // QRPLOT_H
