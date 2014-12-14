#include "propertyinfo.h"


PropertyInfo::PropertyInfo(QString eclName, QString otherName) {
    this->eclName = eclName;
    this->otherName = otherName;
}

PropertyInfo::PropertyInfo(QString eclName, QString otherName, QString fieldUnit) {
    this->eclName = eclName;
    this->otherName = otherName;
    this->fieldUnit = fieldUnit;
}

PropertyInfo::PropertyInfo(QString eclName, QString otherName, QString fieldUnit, QString metricUnit) {
    this->eclName = eclName;
    this->otherName = otherName;
    this->fieldUnit = fieldUnit;
    this->metricUnit = metricUnit;
}

PropertyInfo::PropertyInfo(QString eclName, QString otherName, QString fieldUnit, QString metricUnit, QString description) {
    this->eclName = eclName;
    this->otherName = otherName;
    this->fieldUnit = fieldUnit;
    this->metricUnit = metricUnit;
    this->description = description;
}

QString PropertyInfo::descriptionString() {
    QString infoString = QString("%1: %2").arg(this->eclName).arg(this->otherName);
    if (this->fieldUnit.length() > 0)
        infoString.append(QString("\n Field unit: %1").arg(this->fieldUnit));
    if (this->metricUnit.length() > 0)
        infoString.append(QString("\n Metric unit: %1").arg(this->metricUnit));
    if (this->description.length() > 0)
        infoString.append(QString("\n %1").arg(this->description));
    return infoString;
}
