#ifndef SMREADER_H
#define SMREADER_H

#include <QString>

class SMReader {
private:
    bool fileOpened;

public:
    SMReader(QString filename);
    bool isFileOpen();
};

#endif // SMREADER_H
