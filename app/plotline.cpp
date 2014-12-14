#include "plotline.h"

PlotLine::PlotLine(QVector<double> x, QVector<double> y, QString name, QString unit, QString file) {
    this->x = x;
    this->y = y;
    this->name = name;
    this->unit = unit;
    this->file = file;
    this->ymax = findMax(y);
    this->ymin = findMin(y);
}

double PlotLine::findMax(QVector<double> numbers) {
    double max = 0;
    foreach (double number, numbers) {
        if (number > max)
            max = number;
    }
    return max;
}

double PlotLine::findMin(QVector<double> numbers) {
    double min;
    foreach (double number, numbers) {
        if (number < min)
            min = number;
    }
    return min;
}
