#include "sqltablemodel.h"
#include <QMap>

QMap<int, Qt::CheckState> check_state_map;

sqltablemodel::sqltablemodel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {

}

// setData()方法主要用来设置是否被选中，然后将对应的状态保存到QMap中
bool sqltablemodel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid()) return false;
    if (role == Qt::CheckStateRole && index.column() == 0) {
        check_state_map[index.row()] = (value == Qt::Checked ? Qt::Checked : Qt::Unchecked);
        return true;
    } else {
        return QSqlTableModel::setData(index, value, role);
    }
}

// data()方法主要用来显示，取出QMap中的值，返回对应的状态
QVariant sqltablemodel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();
    if (index.column() != 0) return QSqlTableModel::data(index, role);
    switch(role) {
        case Qt::CheckStateRole:
            if (index.column() == 0) {
                if (check_state_map.contains(index.row())) {
                    return check_state_map[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
                }
                return Qt::Unchecked;
            }
        default:
            return QVariant();
    }
    return QVariant();
}

//flag()方法主要设置用户可选角色，绘制出QCheckBox
Qt::ItemFlags sqltablemodel::flags(const QModelIndex &index) const {
    if (!index.isValid()) return 0;
    if (index.column() == 0) return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
    else return QSqlTableModel::flags(index);
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
