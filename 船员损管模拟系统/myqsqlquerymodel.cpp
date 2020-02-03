#include "myqsqlquerymodel.h"

MyQSqlQueryModel::MyQSqlQueryModel() {

}

bool MyQSqlQueryModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(!index.isValid()) return false;
    if (role == Qt::CheckStateRole && index.column() == 0) {//当该列有复选框且复选框在第0列时
        if (value == Qt::Checked) { //如果复选框为被勾选状态
            check_state_map[index.row()] = Qt::Checked; //将当前行和复选框勾选状态存入map中
            emit sign_checked(index.row()); //发送复选框勾选信号
        }
        else { //如果复选框为未被勾选状态
            check_state_map[index.row()] = Qt::Unchecked; //将当前行和复选框未勾选状态存入map中
            emit sign_unchecked(index.row()); //发送复选框未勾选信号
        }
    }
    return true;
}

QVariant MyQSqlQueryModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid()) return QVariant();
    //当flag()函数中，设置某一列具有Qt::CheckStateRole这种角色后，该列就会显示为一个CheckBox
    if(role == Qt::CheckStateRole) { //判断该列是否有复选框
        if(index.column() == 0) { //当复选框在第0列时
            if (check_state_map.contains(index.row())) //如果map保存了复选框的勾选状态
                return check_state_map[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked; //返回map中保存的复选框状态
            return Qt::Unchecked;
        }
    }
    return QSqlQueryModel::data(index, role);
}

Qt::ItemFlags MyQSqlQueryModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) return 0;
    if (index.column() == 0) { //设置第0列为复选框所在列
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable; //通过Qt::ItemIsUserCheckable绘制复选框
    }
    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable; //
}
