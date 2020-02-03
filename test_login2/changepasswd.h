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
    void clearChangePwdInterface();

private slots:
    void on_btn_changepwd_clicked();
    void on_btn_changepwd_exit_clicked();

private:
    Ui::changepasswd *ui;
};

#endif // CHANGEPASSWD_H
