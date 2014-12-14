#include <unittest++/UnitTest++.h>
#include <rsmreader.h>
#include <smreader.h>
#include <propertylist.h>
#include <property.h>
#include <summary.h>
#include <QList>
#include <QStringList>
#include <QDebug>

const QString rsmPath = "data/10x10.RSM";
const QString smrPath = "data/10x10.SMSPEC";
const QString title = "PEACEMAN_10X10_CORNER";
const int numberOfProperties = 10;
const QStringList properyNames = (QStringList() << "TIME" << "YEARS" << "FWPR" << "FWIR" << "WBHP" << "WBHP" << "WBP" << "WBP" << "CTFAC" << "CTFAC");
const QStringList units = (QStringList() << "DAYS" << "YEARS" << "SM3/DAY" << "SM3/DAY" << "BARSA" << "BARSA" << "BARSA" << "BARSA" << "CPM3/D/B" << "CPM3/D/B");
const QStringList wells = (QStringList() << "N/A" << "N/A" << "N/A" << "N/A" << "INJ" << "PROD" << "INJ" << "PROD" << "PROD" << "INJ");
const QStringList blocks = (QStringList() << "N/A" << "N/A" << "N/A" << "N/A" << "N/A" << "N/A" << "N/A" << "N/A" << "1,1,1" << "13,13,1");

const float timeFirst = 0.0;
const float timeLast = 500.0;
const float wbhpProdFirst = 100.0000;
const float wbhpProdLast = 98.78590;

SUITE(RSMReader) {
    RSMReader data = RSMReader(rsmPath);
    TEST(OpenFile) {
        CHECK(data.isFileOpen() == true);
    }
    TEST(CheckTitle) {
        CHECK(data.getTitle() == title);
    }
    TEST(CheckNumberOfColumnsOnEachLine) {
        QList<QStringList> contents = data.getContent();
        int colsOnFirstLine = contents.first().length();
        bool equalNumberOfCols = true;
        foreach (QStringList line, contents) {
            if (line.length() != colsOnFirstLine) {
                equalNumberOfCols = false;
                break;
            }
        }
        CHECK(equalNumberOfCols == true);
    }
}

SUITE(SMReader) {
    SMReader data = SMReader(smrPath);
}

SUITE(Summary) {
    RSMReader data = RSMReader(rsmPath);
    Summary summary = Summary(data.getTitle(), data.getPropertyList());
    TEST(CheckTitle) {
        CHECK(data.getTitle() == summary.getTitle());
    }
}

SUITE(PropertyList) {
    RSMReader data = RSMReader(rsmPath);
    Summary summary = Summary(data.getTitle(), data.getPropertyList());
    PropertyList propertyList = summary.getProperties();
    TEST(CheckNumberOfProperties) {
        CHECK(propertyList.length() == numberOfProperties);
    }
    TEST(CheckPropertyNames) {
        bool namesOk = true;
        QStringList namesRead = propertyList.getPropertyNames();
        for (int i=0; i < properyNames.length(); ++i) {
            if (namesRead[i] != properyNames[i]) {
                namesOk = false;
                break;
            }
        }
        CHECK(namesOk == true);
    }
    TEST(CheckUnits) {
        bool unitsOk = true;
        for (int i=0; i<propertyList.length(); ++i) {
            if (propertyList.getProperty(i).getUnit() != units[i]) {
                unitsOk = false;
                break;
            }
        }
        CHECK(unitsOk == true);
    }

    TEST(CheckBlocks) {
        bool blocksOk = true;
        for (int i=0; i<propertyList.length(); ++i) {
            if (propertyList.getProperty(i).getBlock() != blocks[i]) {
                blocksOk = false;
                break;
            }
        }
        CHECK(blocksOk == true);
    }
}

SUITE(Property) {
    RSMReader data = RSMReader(rsmPath);
    Summary summary = Summary(data.getTitle(), data.getPropertyList());
    PropertyList propertyList = summary.getProperties();
    Property time = propertyList.getProperty("TIME");
    Property wbhpProd = propertyList.getProperty("WBHP", "PROD");
    TEST(CheckTime) {
        CHECK(time.getValues().first() == timeFirst);
        CHECK(time.getValues().last() == timeLast);
    }
    TEST(CheckWbhpProd) {
        CHECK(wbhpProd.getValues().first() == wbhpProdFirst);
        CHECK(wbhpProd.getValues().last() == wbhpProdLast);
    }
}

int main()
{
    return UnitTest::RunAllTests();
}
