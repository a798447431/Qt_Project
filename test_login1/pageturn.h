#ifndef PAGETURN_H
#define PAGETURN_H

#include <QTableView>
#include <QScrollBar>

class pageturn
{
public:
    pageturn();
    int pageCount(QTableView *p);
    // 跳转到指定页码
    bool pageTo(QTableView *p, int pageNO);
    // 上一页
    bool pageUp(QTableView *p);
    // 下一页
    bool pageDown(QTableView *p);
    // 首页
    bool pageHome(QTableView *p);
    // 尾页
    bool pageEnd(QTableView *p);
};

#endif // PAGETURN_H
