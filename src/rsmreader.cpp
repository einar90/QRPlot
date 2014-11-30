#include "rsmreader.h"

#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QList>

using namespace std;

RSMReader::RSMReader(QString filename) {
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        this->fileOpened = false;
    }
    else {
        this->fileOpened = true;
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            this->contents.append(line);
        }
    }
    file.close();

    // Trim content
    foreach (QString line, this->contents) {
        if (line.trimmed().length() == 1 || line.trimmed().contains("---")) {
            this->contents.removeOne(line);
        }
    }

    // Get title and date; remove headerline from content
    QString headerline = this->contents.first().trimmed().remove(0,15); // Trim start of header
    headerline = headerline.remove(headerline.indexOf("USER"), headerline.length()); // Trim end of header
    QStringList headerlist = headerline.split("DATESTAMP");
    this->title = headerlist.first().remove(headerlist.first().indexOf("ECLIPSE")-1, headerlist.first().length()); // Set title
    this->dateString = headerlist.last().trimmed();
    this->contents.removeFirst();
    qDebug() << "Title: " << this->title;
    qDebug() << "DateString: " << this->dateString;

    // Read property headers and units
    QStringList properties = this->contents.first().split("     "); // Split at five spaces
    this->contents.pop_front(); // Remove property header line
    QStringList units = this->contents.first().split("     "); // Split at five spaces
    this->contents.pop_front(); // Remove units line

    while (properties.length() > 0) {
        if (properties.first().trimmed().length() > 0) {
            this->propertyHeaders.append(properties.first().trimmed());
            properties.pop_front();
        }
        else
            properties.pop_front();
    }
    while (units.length() > 0) {
        if (units.first().trimmed().length() > 0) {
            this->units.append(units.first().trimmed());
            units.pop_front();
        }
        else
            units.pop_front();
    }
    qDebug() << "Property headers: " << this->propertyHeaders;
    qDebug() << "Units: " << this->units;

    // Get wells
    QStringList wells = this->contents.first().split("     "); // Split at five spaces
    foreach (QString well, wells) {
        if (well.trimmed().length() == 0)
            wells.removeOne(well);
        else
            well = well.trimmed();
    }
    qDebug() << "Wells: " << wells;


    qDebug() << this->contents;
}

bool RSMReader::isFileOpen() {
    return this->fileOpened;
}



void RSMReader::readHeaders(QString headers, QString units, QString wells) {
    qDebug() << headers;
    qDebug() << units;
    qDebug() << wells;
}

QList<QString> RSMReader::getHeaders(){
}
