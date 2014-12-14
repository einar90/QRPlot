#include "property.h"
#include <QRegExp>

Property::Property(QString name, QString unit, QString well, QString block, QList<float> values) {
    this->name = name;
    this->unit = unit;
    foreach (float value, values) {
        this->values.append(value);
    }
    if (well.trimmed().length() != 0)
        this->well = well;
    if (block.trimmed().length() != 0)
        this->block = block;
}

Property::Property(QString name, QString unit, QString well, QString block, QStringList values) {
    this->name = name;
    this->unit = unit;
    if (well.trimmed().length() != 0)
        this->well = well;
    if (block.trimmed().length() != 0)
        this->block = block.replace("  ", ",").remove(QRegExp("\\s"));

    foreach (QString element, values) {
        this->values.append(element.toFloat());
    }
}

QString Property::getName() {
    return this->name;
}

QString Property::getUnit() {
    return this->unit;
}

QString Property::getWell() {
    if (this->well != NULL)
        return this->well;
    else
        return "N/A";
}

QString Property::getBlock() {
    if (this->block != NULL)
        return this->block;
    else
        return "N/A";
}

QVector<double> Property::getValues() {
    return this->values;
}
