#include "propertyinfolist.h"

PropertyInfoList::PropertyInfoList() {
    this->infoList.append(PropertyInfo("TIME", "Time", "Days", "Days", "Days since simulation start."));
    this->infoList.append(PropertyInfo("YEARS", "Years", "Yers", "Years", "Years since simulation start."));
    this->infoList.append(PropertyInfo("FWPR", "Field Water Production Rate", "stb/Day", "sm3/day", "Total rate of water production from all wells."));
    this->infoList.append(PropertyInfo("FWIR", "Field Water Injection Rate", "stb/day", "sm3/day"));
    this->infoList.append(PropertyInfo("WBHP", "Well Bottom Hole Pressure", "psia", "barsa"));
    this->infoList.append(PropertyInfo("WBP", "Well Block Pressure", "psia", "barsa"));
    this->infoList.append(PropertyInfo("CTFAC", "Connection Transmissibility Factor", "Cp*stb/day/bar", "Cp*m3/day/bar"));

}

QString PropertyInfoList::getPropertyInfo(QString eclName) {
    for (int i=0; i < this->infoList.length(); ++i) {
        if (this->infoList[i].eclName == eclName) {
            return infoList[i].descriptionString();
        }
    }
    return "";
}
