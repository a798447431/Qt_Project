#ifndef MYMODEL_H
#define MYMODEL_H
#include <QSqlQueryModel>
#include "headerview.h"
class MyModel : public QSqlQueryModel {

    Q_OBJECT



public:

    MyModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool setData( const QModelIndex & index, const QVariant & value, int role);

    QMap<QVariant, Qt::CheckState> check_state_map;

    public slots:

          void getCheckBoxChanged(bool isOn);



};


#endif // MYMODEL_H
