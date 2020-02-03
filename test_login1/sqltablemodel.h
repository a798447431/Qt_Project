#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QModelIndex>
#include <QVariant>

class sqltablemodel : public QSqlTableModel
{
public:
    sqltablemodel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // SQLTABLEMODEL_H
