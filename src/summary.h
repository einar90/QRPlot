#ifndef SUMMARY_H
#define SUMMARY_H

#include <property.h>
#include <propertylist.h>

class Summary {
private:
    PropertyList propertyList;
    QString title;
public:
    Summary(QString title, PropertyList propertyList);
    QString getTitle();
    PropertyList getProperties();
    QStringList getPropertyNames();
};

#endif // SUMMARY_H
