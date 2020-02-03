#include "get_tableview_info.h"
#include <QString>

get_tableview_info::get_tableview_info(QObject *parent) : QObject(parent)
{

}

get_tableview_info * get_tableview_info::gti = new get_tableview_info;

get_tableview_info * get_tableview_info::getInfo() {
    return gti;
}

void get_tableview_info::addTempInfo() {
    emit getTempInfo();
}
