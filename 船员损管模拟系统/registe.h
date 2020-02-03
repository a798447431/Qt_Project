#ifndef REGISTE_H
#define REGISTE_H

#include <QDialog>

//新建用户类

namespace Ui {
class registe;
}

class registe : public QDialog
{
    Q_OBJECT

public:
    explicit registe(QWidget *parent = nullptr);
    ~registe();
    void clearUserInterface();

private slots:
    void on_btn_registe_clicked();
    void on_btn_register_exit_clicked();

private:
    Ui::registe *ui;
};

#endif // REGISTE_H
