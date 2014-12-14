#ifndef QRPLOT_H
#define QRPLOT_H

#include <QMainWindow>
#include <QItemSelectionModel>
#include <summary.h>
#include <graph.h>

namespace Ui {
class QRPlot;
}

class QRPlot : public QMainWindow
{
    Q_OBJECT

public:
    explicit QRPlot(QWidget *parent = 0);
    ~QRPlot();

private slots:
    void on_actionOpen_triggered();

    void on_actionExportGraphics_triggered();

    void on_actionExportDataCSV_triggered();

    void updateSummaryTree();

    void updatePlottedPropertiesList();

    void updateDataTable();

    void selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/);

    void selectedPlottedLineSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/);

    void plotLine(QString propertyName, QString dataTitle);

    Summary getSummaryWithTitle(QString title);

    void on_actionOpen_file_triggered();

private:
    Ui::QRPlot *ui;
    Graph graph;
};

#endif // QRPLOT_H
