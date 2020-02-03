#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase> //QSqlDatabase类用来创建连接数据库实例,一个QSqlDatabase的实例代表了一个数据库连接
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDriver> //导入数据库驱动
#include <QSqlRecord> //该类用来封装数据库记录，调试用，正常功能没用到

class database
{
public:
    database();
    void connect_database();
    QSqlDatabase return_db();

private:
    QSqlDatabase _db;
};

#endif // DATABASE_H
