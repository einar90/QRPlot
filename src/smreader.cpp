#include "smreader.h"
#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>

/*
 * Reads binary summary files, i.e. smspec+unsmry
*/
SMReader::SMReader(QString filename) {
    QFile file(filename);
    QStringList rawContents;
    if(!file.open(QIODevice::ReadOnly)) {
        this->fileOpened = false;
    }
    else {
        this->fileOpened = true;
        //QTextStream in(&file);
        QByteArray blob = file.readAll();

//        while (!in.atEnd()) {
//            QString line = in.readLine();
//            qDebug() << line;
//            rawContents.append(line);
//        }
    }
    file.close();
    //qDebug() << rawContents;
}
