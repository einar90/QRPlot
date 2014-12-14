#ifndef GRAPH_H
#define GRAPH_H

#include <plotline.h>
#include <qcustomplot.h>
#include <QList>

class Graph {
private:
    QCustomPlot *plot;
    void redraw();
public:
    QList<PlotLine> lines;
    Graph(QCustomPlot *plot);
    Graph();
    void addLine(PlotLine line);
    void removeLine(QString name, QString file);
};

#endif // GRAPH_H
