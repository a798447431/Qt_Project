#ifndef MAINMENU_H
#define MAINMENU_H

//用户管理

#include <QMainWindow>
#include <QSqlQuery>
#include <QTimer>
#include "registe.h" //添加用户
#include "changepasswd.h" //修改当前用户密码
#include "changeinfo.h" //修改用户信息
#include "pageturn.h" //分页栏
#include "lockscreen.h" //锁屏
#include "myqsqlquerymodel.h" //重构的sqlquerymodel类，支持复选框

namespace Ui {
    class mainmenu;
}

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();
    void start_timer(); //启动定时器，用来在刚进入管理窗口时触发槽函数, 显示表格信息和初始化系统状态栏
    bool eventFilter(QObject *target, QEvent *event); // 事件过滤器，用来过滤QTableView的滚轮事件
    void checkbox_select_all(); //全选当前页面的复选框
    void checkbox_deselect_all(); //取消全选复选框

signals:
    void SignFather(); //用来返回系统主窗口的信号
    void cancle_checkbox_select(); //用来取消表头复选框勾选的信号

private slots:
    void init_system(); //初始化用户管理窗口信息
    void on_btn_registe_clicked(); //新建用户窗口
    void on_btn_exit_clicked();//退出当前窗口
    void on_btn_minimize_clicked(); //最小化
    void on_btn_changpwd_clicked(); //修改当前用户密码
    void on_btn_findinfo_clicked(); //查询信息
    void init_tableview(); //初始化TableView表头信息
    void init_show_sqlinfo(); //初始化TableView显示信息，默认显示数据库全部条目
    void on_btn_resetting_clicked(); //重置TableView显示信息
    void on_btn_delete_clicked(); //删除TableView条目
    void on_btn_edit_clicked(); //编辑TableView条目
    void on_btn_pageup_clicked(); //上翻页
    void on_btn_pagedown_clicked(); //下翻页
    void update_pagenum(); //更新页数信息
    void on_btn_pagehome_clicked(); //回到第一页
    void on_btn_end_clicked(); //跳转到最后一页
    void on_btn_lockscreen_clicked(); //锁屏
    void init_system_state(); //初始化系统状态栏
    void timerUpdate(); //更新系统时间
    void on_btn_return_clicked();// 返回系统主窗口
    void slotCheckBoxCheck(int row); //获取复选框选择的条目行数
    void slotCheckBoxUncheck(int row); //获取取消复选框选择的条目行数

private:
    Ui::mainmenu *ui;
    registe r; //新建用户窗口对象
    changepasswd cp; //修改密码窗口对象
    changeinfo ci; //修改条目信息窗口对象
    lockscreen ls; //锁屏窗口对象
    MyQSqlQueryModel *model; //重构的SqlQueryModel对象，QSqlQueryModel类为SQL的结果集提供了一个只读的数据模型，我在其模型中插入了复选框
    pageturn pg; //分页栏对象
    QTimer *m_pTimer; //定时器对象
    int currentPage; //分页栏当前页数
};

#endif // MAINMENU_H
