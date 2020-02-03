#ifndef CHANGEPASSWD_H
#define CHANGEPASSWD_H

#include <QDialog>

namespace Ui {
class changepasswd;
}

class changepasswd : public QDialog
{
    Q_OBJECT

public:
    explicit changepasswd(QWidget *parent = nullptr);
    ~changepasswd();
    void clearChangePwdInterface(); //清空信息

private slots:
    void on_btn_changepwd_clicked(); //修改密码
    void on_btn_changepwd_exit_clicked(); //退出

private:
    Ui::changepasswd *ui;
};

#endif // CHANGEPASSWD_H
