#include "graph.h"
#include <QDebug>
#include <QColor>
#include <QFont>
#include <QLocale>

// List of colors to be used in graphs
const QList<QColor> colors = (QList<QColor>()
                              << QColor("#F44336") // Red
                              << QColor("#4CAF50") // Green
                              << QColor("#2196F3") // Blue
                              << QColor("#FFC107") // Amber
                              << QColor("#795548") // Brown
                              << QColor("#E91E63") // Pink
                              << QColor("#8BC34A") // Light Green
                              << QColor("#3F51B5") // Indigo
                              << QColor("#FF5722") // Deep orange
                              << QColor("#009688") // Teal
                              << QColor("#00BCD4") // Cyan
                              << QColor(Qt::red)
                              << QColor(Qt::green)
                              << QColor(Qt::blue)
                          );

Graph::Graph(){}

Graph::Graph(QCustomPlot *plot) {
    this->plot = plot;

    this->plot->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    this->plot->legend->setVisible(true);
    this->plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    this->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
}

void Graph::addLine(PlotLine line) {
    this->lines.append(line);
    this->redraw();
}

void Graph::removeLine(QString name, QString file) {
    for (int i=0; i < this->lines.length(); ++i) {
        if (lines[i].name == name &&  lines[i].file == file) {
            this->lines.removeAt(i);
            qDebug() << "Removed line";
            break;
            qDebug() << "broke";
        }
    }
    this->redraw();
}

void Graph::redraw() {
    if (this->lines.length() == 0) {
        plot->clearGraphs();
        return;
    }
    double xmin = this->lines.first().x.first();
    double xmax = this->lines.first().x.last();
    double ymin = 0;
    double ymax = 0;

    // Redraw graphs
    plot->clearGraphs();
    for (int i=0; i<this->lines.length(); ++i) {
        plot->addGraph();
        plot->graph(i)->setPen(colors[i]);
        plot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));
        plot->graph(i)->setName(QString("%1:%2 [%3]").arg(lines[i].file).arg(lines[i].name).arg(lines[i].unit));
        plot->graph(i)->setData(lines[i].x, lines[i].y);
        if (lines[i].ymax > ymax)
            ymax = lines[i].ymax;
        if (lines[i].ymin < ymin)
            ymin = lines[i].ymin;
    }
    if (this->lines.length() <= 1)
        this->plot->yAxis->setLabel(lines.first().unit);
    else
        this->plot->yAxis->setLabel("");
    this->plot->xAxis->setLabel("Time (days)");
    this->plot->xAxis->setRange(xmin, xmax);
    this->plot->yAxis->setRange(ymin,ymax+ymax/10.0);
    this->plot->replot();
}
