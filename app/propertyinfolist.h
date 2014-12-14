#ifndef PROPERTYINFOLIST_H
#define PROPERTYINFOLIST_H

#include <QString>
#include <QList>
#include <propertyinfo.h>

class PropertyInfoList {
private:
    QList<PropertyInfo> infoList;
public:
    PropertyInfoList();
    QString getPropertyInfo(QString eclName);
};

#endif // PROPERTYINFOLIST_H
