#include "database.h"

database::database()
{

}

void database::connect_database() {
    _db = QSqlDatabase::addDatabase("QMYSQL"); //设置数据库类型为MySql数据库
    _db.setHostName("localhost"); //设置数据库主机名
    _db.setDatabaseName("info"); //设置数据库名
    _db.setUserName("root"); //设置数据库登入用户名
    _db.setPort(3306); //设置数据库端口
    _db.setPassword("szt3536132"); //设计数据库登入密码
    if(!_db.open()) { //如果数据库打不开，报错
        qDebug()<< "Error";
    }
    else {
        qDebug()<< "Ok";
    }
}

QSqlDatabase database::return_db() {
    return _db;
}
