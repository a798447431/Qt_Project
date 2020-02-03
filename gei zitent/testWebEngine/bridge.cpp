#if _MSC_VER >=1600 //VS2010版本号是1600
#pragma execution_character_set("utf-8")
#endif


#include "bridge.h"
#include <QMessageBox>

bridge* bridge::instance()
{
    static bridge s_obj;
    return &s_obj;
}

bridge::bridge()
{
}

void bridge::showMsgBox(QString msg)
{
    QMessageBox::information(NULL, "Info", msg);

}
