#ifndef MYQSQLQUERYMODEL_H
#define MYQSQLQUERYMODEL_H

#include <QObject>
#include <QtGui>
#include <QApplication>
#include <QSqlQueryModel>
#include <QMap>
#include <QHeaderView>
#include <QCheckBox>

/*
 * 重写SqlQueryModel使SqlQueryModel支持显示复选框
 * 参考网址：https://www.iteye.com/blog/qimo601-1530232
*/

class MyQSqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    MyQSqlQueryModel();
    bool setData(const QModelIndex &, const QVariant &, int) override; //选择QCheckbox，修改Model中的数据
    QVariant data(const QModelIndex &item, int) const override; // 判断复选框的勾选状态
    Qt::ItemFlags flags(const QModelIndex &) const override; //设置某一列为可选角色，绘画出QCheckBox
    QMap<int, Qt::CheckState> check_state_map; //map用来存储复选框的勾选状态

signals:
    void sign_checked(int row); //发送复选框勾选信号，并将对应的行号发给槽函数
    void sign_unchecked(int row); //发送复选框取消勾选信号，并将对应的行号发给槽函数

};

/*
 * 重写HeaderViewPrivate使表头支持显示复选框
 * 参考网址：https://blog.csdn.net/sinat_36921713/article/details/100011552
*/

class HeaderViewPrivate : public QHeaderView
{
    Q_OBJECT

public:
    explicit HeaderViewPrivate(Qt::Orientation orientation, QWidget * parent = 0)
        : QHeaderView(orientation, parent) {
        m_headerCbx = new QCheckBox(this); //生成QCheckBox实例
        m_headerCbx->setVisible(true); //设置QCheckBox可见
        connect(m_headerCbx, &QAbstractButton::clicked, this, &HeaderViewPrivate::checked); //将QCheckBox的勾选信号与HeaderViewPrivate的勾选函数绑定
    }

signals:
    void checked(bool); //复选框勾选信号

private slots:
    void unchackedbox() { //该槽函数将QCheckBox设置成取消勾选状态
        m_headerCbx->setCheckState(Qt::Unchecked);
        return ;
    }

protected:
    void updateGeometries() { //复选框显示位置
        m_headerCbx->move(sectionPosition(0) + 3, 9); // sectionPosition(0) + x, y， x为修改复选框横坐标，y为修改复选框纵坐标
    }

private:
    QCheckBox *m_headerCbx;
};

#endif
