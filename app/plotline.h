#ifndef PLOTLINE_H
#define PLOTLINE_H

#include <QVector>
#include <QString>

class PlotLine {
private:
    double findMax(QVector<double> numbers);
    double findMin(QVector<double> numbers);
public:
    QVector<double> x;
    QVector<double> y;
    QString name;
    QString unit;
    QString file;
    double ymin;
    double ymax;
    PlotLine(QVector<double> x, QVector<double> y, QString name, QString unit, QString file);
};

#endif // PLOTLINE_H
