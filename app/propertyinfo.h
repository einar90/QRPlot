#ifndef PROPERTYINFO_H
#define PROPERTYINFO_H

#include <QString>

class PropertyInfo {
public:
    QString eclName;
    QString otherName;
    QString fieldUnit;
    QString metricUnit;
    QString description;
    PropertyInfo(QString eclName, QString otherName);
    PropertyInfo(QString eclName, QString otherName, QString fieldUnit);
    PropertyInfo(QString eclName, QString otherName, QString fieldUnit, QString metricUnit);
    PropertyInfo(QString eclName, QString otherName, QString fieldUnit, QString metricUnit, QString description);
    QString descriptionString();
};

#endif // PROPERTYINFO_H
