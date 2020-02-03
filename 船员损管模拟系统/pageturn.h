#ifndef PAGETURN_H
#define PAGETURN_H

#include <QTableView>
#include <QScrollBar>

/*
 * 自定义分页栏 写的比较烂而且有BUG，如果某一页没有足够的条目，则会将上一页的一些信息显示在当前页，这样也给我实现当前页复选框全选功能
 * 带来了麻烦，如果当用户跳到没有足够的条目的页时，勾选则不会从当前页的第一行开始勾选，我当前没有想到好的实现办法。
 *
*/
class pageturn
{
public:
    pageturn();
    //统计总页数
    int pageCount(QTableView *p);
    //统计当前页条目数
    int pageLine(QTableView *p);
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
