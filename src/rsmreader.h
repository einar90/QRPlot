#ifndef RSMREADER_H
#define RSMREADER_H

#include <QString>
#include <QList>
#include <QStringList>

#include "property.h"
#include "propertylist.h"

using namespace std;

class RSMReader {
private:
    bool fileOpened;
    QString title;
    QList<QStringList> contents;
    PropertyList propertyList;

public:
    RSMReader(QString filename);
    bool isFileOpen();
    QString getTitle();
    QList<QStringList> getContent();
    PropertyList getPropertyList();
};

#endif // RSMREADER_H
