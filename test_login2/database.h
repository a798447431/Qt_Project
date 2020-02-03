#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QDebug>

class database
{
public:
    database();
    static void connect_database();
    static QSqlDatabase GetQSqlDatabase();

private:
    static QSqlDatabase _db;
};

#endif // DATABASE_H
