#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui { class addStu; }
QT_END_NAMESPACE

class addStu : public QDialog
{
    Q_OBJECT

public:
    addStu(QWidget *parent = nullptr);
    ~addStu();
    void clearUserInterface();
    void writeToFile(QString cnt);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::addStu *ui;
};
#endif // ADDSTU_H
