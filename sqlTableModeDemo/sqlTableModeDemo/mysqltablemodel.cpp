#include "mysqltablemodel.h"

MySqlTableModel::MySqlTableModel(QObject *parent, QSqlDatabase db) :
    QSqlTableModel(parent, db)
{

}

QVariant MySqlTableModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QSqlQueryModel::data(item, role);
    if(role ==  Qt::TextAlignmentRole )
    {
        value = (Qt::AlignCenter);
        return value;
    }
    return value;
}
