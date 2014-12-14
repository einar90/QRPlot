#include "propertylist.h"
#include <QDebug>

PropertyList::PropertyList() {
    this->propertyList.clear();
}

PropertyList::PropertyList(Property property) {
    this->propertyList.append(property);
}

PropertyList::PropertyList(QList<Property> propertyList) {
    this->propertyList.append(propertyList);
}

void PropertyList::addProperty(Property property) {
    this->propertyList.append(property);
}

Property PropertyList::getProperty(QString name) {
    for (int i=0; i < this->propertyList.length(); ++i) {
        if (this->propertyList[i].getName() == name)
            return this->propertyList[i];
    }
}

Property PropertyList::getProperty(QString name, QString well) {
    for (int i=0; i < this->propertyList.length(); ++i) {
        if (this->propertyList[i].getName() == name && this->propertyList[i].getWell() == well)
            return this->propertyList[i];
    }
}

Property PropertyList::getProperty(int i) {
    return this->propertyList[i];
}

int PropertyList::length() {
    return this->propertyList.length();
}

Property PropertyList::first() {
    return this->propertyList.first();
}

Property PropertyList::last() {
    return this->propertyList.last();
}

QStringList PropertyList::getPropertyNames() {
    QStringList names;
    for (int i=0; i < this->propertyList.length(); ++i) {
        names.append(this->propertyList[i].getName());
    }
    return names;
}
