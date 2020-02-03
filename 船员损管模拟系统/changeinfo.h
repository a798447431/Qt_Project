#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class changeinfo;
}

class changeinfo : public QDialog
{
    Q_OBJECT

public:
    explicit changeinfo(QWidget *parent = nullptr);
    ~changeinfo();
    void start_timer(); //启动定时器

private slots:
    void get_user_info(); //获取用户信息
    void on_btn_changeinfo_cancle_clicked(); //取消
    void on_btn_changeinfo_confirm_clicked(); //修改用户信息
    void clear_info(); //清空信息

private:
    Ui::changeinfo *ui;
    QTimer *m_pTimer;
};

#endif // CHANGEINFO_H
