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
    void on_btn_login_clicked();
    void on_btn_exit_clicked();

private:
    Ui::loginwindow *ui;
    main_menu m;
};
#endif // LOGINWINDOW_H
