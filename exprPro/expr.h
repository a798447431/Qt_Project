#ifndef EXPR_H
#define EXPR_H

#include <QDialog>
#include <QString>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class expr; }
QT_END_NAMESPACE

class expr : public QDialog
{
    Q_OBJECT

public:
    expr(QWidget *parent = nullptr);
    ~expr();

private slots:
    void getBtn0();

    void getBtn1();

    void getBtn2();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_clear_clicked();

    void on_btn_equal_clicked();

    void on_btn_plus_clicked();

    void on_btn_sub_clicked();

    void on_btn_mul_clicked();

    void on_btn_div_clicked();

private:
    Ui::expr *ui;
    model *_model;
    QString tmp;
};
#endif // EXPR_H
