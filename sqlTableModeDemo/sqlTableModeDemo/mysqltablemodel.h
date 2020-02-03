#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H

#include <QSqlTableModel>

class MySqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit MySqlTableModel(QObject *parent, QSqlDatabase db);

signals:

protected:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;

public slots:

};

#endif // MYSQLTABLEMODEL_H
