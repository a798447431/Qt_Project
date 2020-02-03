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
    void start_timer();

private slots:
    void get_user_info();
    void on_btn_changeinfo_cancle_clicked();
    void on_btn_changeinfo_confirm_clicked();
    void clear_info();

private:
    Ui::changeinfo *ui;
    QTimer *m_pTimer;
};

#endif // CHANGEINFO_H
