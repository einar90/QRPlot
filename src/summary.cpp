#include "summary.h"

Summary::Summary(QString title, PropertyList propertyList) {
    this->title = title;
    this->propertyList = propertyList;
}

QString Summary::getTitle() {
    return this->title;
}

PropertyList Summary::getProperties() {
    return this->propertyList;
}

QStringList Summary::getPropertyNames() {
    QStringList names;
    for (int i=0; i < this->propertyList.length(); ++i) {
        names.append(this->propertyList.getProperty(i).getName());
    }
    return names;
}
