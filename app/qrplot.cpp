#include "qrplot.h"
#include "ui_qrplot.h"

#include "rsmreader.h"
#include "property.h"
#include "propertylist.h"
#include "summary.h"
#include "graph.h"
#include "plotline.h"
#include "propertyinfolist.h"

#include <QDebug>
#include <QFileDialog>
#include <QList>

#include <QStandardItemModel>
#include <QStandardItem>
#include <QListWidget>
#include <qcustomplot.h>

QList <Summary> summaries;
QItemSelectionModel *selectionModel;
QItemSelectionModel *selectionModelPlotted;
PropertyInfoList propertyInfo = PropertyInfoList();

QRPlot::QRPlot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPlot)
{
    ui->setupUi(this);
    this->graph = Graph(ui->plot);
}

QRPlot::~QRPlot()
{
    delete ui;
}

void QRPlot::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open RSM file"), "/home/", tr("Readable summary files (*.RSM)"));
    RSMReader file = RSMReader(filename);
    summaries.append(Summary(file.getTitle(), file.getPropertyList()));
    qDebug() << "Open files:";
    foreach (Summary summary, summaries) {
        qDebug() << summary.getTitle();
    }
    updateSummaryTree();

}

void QRPlot::updateSummaryTree() {
    QStandardItemModel *model = new QStandardItemModel();

    for (int i=0; i < summaries.length(); ++i) {
        QStandardItem *summary = new QStandardItem(summaries[i].getTitle());
        model->appendRow(summary);
        for (int j=0; j < summaries[i].getPropertyNames().length(); ++j) {
            QStandardItem *property = new QStandardItem(summaries[i].getPropertyNames()[j]);
            summary->appendRow(property);
        }
    }
    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    selectionModel = ui->treeView->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
                this, SLOT(selectionChangedSlot(const QItemSelection &, const QItemSelection &)));
}

void QRPlot::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/) {
    const QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    QString parent = index.parent().data(Qt::DisplayRole).toString();
    qDebug() << "Selected item: " << selectedText;
    qDebug() << "Parent: " << parent;
    plotLine(selectedText, parent);
    ui->propertyInfo->clear();
    ui->propertyInfo->insertPlainText(propertyInfo.getPropertyInfo(selectedText));
}

void QRPlot::plotLine(QString propertyName, QString dataTitle) {
    qDebug() << "Plotting " << propertyName;
    Summary summary = getSummaryWithTitle(dataTitle);
    Property xProp = summary.getProperties().getProperty("TIME");
    Property yProp = summary.getProperties().getProperty(propertyName);
    PlotLine newLine = PlotLine(xProp.getValues(), yProp.getValues(), propertyName, yProp.getUnit(), dataTitle);
    this->graph.addLine(newLine);
    this->updatePlottedPropertiesList();
}

void QRPlot::updateDataTable() {
    /*
     * Update the table in tab 2 with the plotted data
     */
}

void QRPlot::updatePlottedPropertiesList() {
    QStandardItemModel *model = new QStandardItemModel();
    for (int i=0; i < this->graph.lines.length(); ++i) {
        QStandardItem *line = new QStandardItem(QString("%1:%2").arg(this->graph.lines[i].file).arg(graph.lines[i].name));
        model->appendRow(line);
    }
    ui->plottedProperties->setModel(model);
    selectionModelPlotted = ui->plottedProperties->selectionModel();
    connect(selectionModelPlotted, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
                this, SLOT(selectedPlottedLineSlot(const QItemSelection &, const QItemSelection &)));
}

void QRPlot::selectedPlottedLineSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/) {
    const QModelIndex index = ui->plottedProperties->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    QString file = selectedText.split(":")[0];
    QString name = selectedText.split(":")[1];
    qDebug() << "Property: " << name;
    qDebug() << "File: " << file;
    this->graph.removeLine(name, file);
    this->updatePlottedPropertiesList();
}

Summary QRPlot::getSummaryWithTitle(QString title) {
    foreach (Summary summary, summaries) {
        if (summary.getTitle() == title)
            return summary;
    }
    return summaries[0]; // Return first summary if for some reason the requested one is not found
}

void QRPlot::on_actionExportGraphics_triggered()
{
    qDebug() << "Export graphics clicked";
}

void QRPlot::on_actionExportDataCSV_triggered()
{
    qDebug() << "Export data clicked";
}


void QRPlot::on_actionOpen_file_triggered()
{
    QRPlot::on_actionOpen_triggered();
}
