#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QResizeEvent>
#include <QTimer>
#include "registe.h"
#include "changepasswd.h"
#include "changeinfo.h"
#include "pageturn.h"
#include "lockscreen.h"
#include "sqltablemodel.h"

namespace Ui {
    class mainmenu;
}

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();
    void start_timer();

signals:
    void SignFather();

private slots:
    void init_system();
    void on_btn_registe_clicked();
    void on_btn_exit_clicked();
    void on_btn_minimize_clicked();
    void on_btn_changpwd_clicked();
    void on_btn_findinfo_clicked();
    void init_tableview();
    void init_show_sqlinfo();
    void on_btn_resetting_clicked();
    //void on_tableView_clicked(const QModelIndex &index);
    void on_btn_delete_clicked();
    void on_btn_edit_clicked();
    void on_btn_pageup_clicked();
    void on_btn_pagedown_clicked();
    void update_pagenum();
    void on_btn_pagehome_clicked();
    void on_btn_end_clicked();
    void on_btn_lockscreen_clicked();
    void init_system_state();
    void timerUpdate();
    void on_btn_return_clicked();

private:
    Ui::mainmenu *ui;
    registe r;
    changepasswd cp;
    changeinfo ci;
    lockscreen ls;
    //QSqlQueryModel *model;
    pageturn pg;
    QTimer *m_pTimer;
    sqltablemodel *pModel;
    int currentPage;
};

#endif // MAINMENU_H
