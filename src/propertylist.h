#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <property.h>
#include <QList>
#include <QStringList>

class PropertyList {
private:
    QList<Property> propertyList;
public:
    PropertyList();
    PropertyList(Property property);
    PropertyList(QList<Property> propertyList);

    void addProperty(Property property);
    void removeProperty(Property property);
    Property getProperty(QString name);
    Property getProperty(int i);
    Property getProperty(QString name, QString well);

    int length();
    Property first();
    Property last();

    QStringList getPropertyNames();
};

#endif // PROPERTYLIST_H
