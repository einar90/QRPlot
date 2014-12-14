#include "rsmreader.h"

#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QList>
#include <QRegExp>

using namespace std;

RSMReader::RSMReader(QString filename) {
    QFile file(filename);
    QStringList rawContents;
    if(!file.open(QIODevice::ReadOnly)) {
        this->fileOpened = false;
    }
    else {
        this->fileOpened = true;
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            rawContents.append(line);
        }
    }
    file.close();

    // Remove empty lines
    foreach (QString line, rawContents) {
        if (line.trimmed().length() == 0 ) {
            rawContents.removeOne(line);
        }
    }

    // Set date in object; remove headerline from raw contents list
    this->title = rawContents.first().trimmed().remove("SUMMARY OF RUN ");
    rawContents.removeFirst(); // Remove headerline from raw content list

    // Split raw contents by tab
    foreach (QString line, rawContents) {
        this->contents.append(line.split("\t"));
    }

    // The RSM files often start with an empty column. Check if it does
    bool startsWithEmptyColumn = true;
    foreach (QStringList line, this->contents) {
        if (line.first().trimmed().length() > 0) {
            startsWithEmptyColumn = false;
            break;
        }
    }

    // If the RSM file starts with an empty column, remove it
    if (startsWithEmptyColumn) {
        for (int i=0; i < this->contents.length(); ++i) {
            this->contents[i].pop_front();
        }
    }

    // Remove trailing empty elements
    for (int i=0; i < this->contents.length(); i++) {
        if (this->contents[i].last().trimmed().length() == 0) {
            this->contents[i].pop_back();
        }
    }

    // Trim whitespace from elements
    for (int i=0; i < this->contents.length(); i++) {
        for (int j=0; j < this->contents[i].length(); j++) {
            this->contents[i][j] = this->contents[i][j].trimmed();
        }
    }

    // Create propertylist and property objects
    for (int j=0; j < this->contents.first().length(); ++j) {
        QStringList column;
        for (int i=0; i < contents.length(); ++i) {
            column.append(contents[i][j]);
        }
        Property newProperty(column[0], column[1], column[2], column[3], column.mid(4,column.length()));
        this->propertyList.addProperty(newProperty);
    }
}

bool RSMReader::isFileOpen() {
    return this->fileOpened;
}

PropertyList RSMReader::getPropertyList() {
    return this->propertyList;
}

QString RSMReader::getTitle() {
    return this->title;
}

QList<QStringList> RSMReader::getContent() {
    return this->contents;
}
