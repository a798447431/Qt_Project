#ifndef INITDB_H
#define INITDB_H

#include <QtSql>


QSqlError initDb()
{
    QSqlDatabase db;
        if(QSqlDatabase::contains("qt_sql_default_connection"))
          db = QSqlDatabase::database("qt_sql_default_connection");
        else
          db = QSqlDatabase::addDatabase("QMYSQL");

           db.setHostName("localhost");
           db.setDatabaseName("info");
           db.setUserName("root");
           db.setPassword("szt3536132");


    if (!db.open())
        return db.lastError();

    return QSqlError();
}




#endif // INITDB_H
