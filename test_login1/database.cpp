#include "database.h"

database::database()
{
}

QSqlDatabase database::_db = QSqlDatabase::addDatabase("QMYSQL");

void database::connect_database() {
    _db.setHostName("localhost");
    _db.setDatabaseName("info");
    _db.setUserName("root");
    _db.setPort(3306);
    _db.setPassword("szt3536132");
    if(!_db.open()) {
        qDebug()<< "Error";
    }
    else {
        qDebug()<< "Ok";
    }
}

QSqlDatabase database::GetQSqlDatabase() {
    return database::_db;
}
