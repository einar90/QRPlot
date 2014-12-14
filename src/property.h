#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QList>
#include <QStringList>
#include <QVector>

class Property {
private:
    QString name;
    QString unit;
    QString well;
    QString block;
    QVector<double> values;
public:
    Property(QString name, QString unit, QString well, QString block, QList<float> values);
    Property(QString name, QString unit, QString well, QString block, QStringList values);

    QString getName();
    QString getUnit();
    QString getWell();
    QString getBlock();
    QVector<double> getValues();
};

#endif // PROPERTY_H
