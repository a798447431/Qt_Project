#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>
#include "mainmenu.h"
//#include "changepasswd.h"
//#include "lockscreen.h"

namespace Ui {
class main_menu;
}

class main_menu : public QWidget
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_btn_mainmenu_help_clicked();
  //  void on_btn_mainmenu_lockscreen_clicked();
    void on_btn_mainmenu_minimize_clicked();
  //  void on_btn_mainmenu_changpwd_clicked();
    void on_btn_mainmenu_exit_clicked();
    void on_btn_userinfo_manage_clicked();
    void main_init_system_state();
    void main_timerUpdate();
    void return_main_menu();

private:
    Ui::main_menu *ui;
    mainmenu mm;
   // changepasswd cp;
    //lockscreen ls;
};

#endif // MAIN_MENU_H
