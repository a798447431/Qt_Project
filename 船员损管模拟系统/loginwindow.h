#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "main_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginwindow; }
QT_END_NAMESPACE

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private slots:
    void on_btn_login_clicked(); //登录按钮槽函数
    void on_btn_exit_clicked(); //退出按钮槽函数

private:
    Ui::loginwindow *ui;
    main_menu m; //生成主界面对象
};
#endif // LOGINWINDOW_H
