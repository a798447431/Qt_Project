#ifndef LOGINWIDOW_H
#define LOGINWIDOW_H

#include <QDialog>

namespace Ui {
class loginwidow;
}

class loginwidow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwidow(QWidget *parent = nullptr);
    ~loginwidow();

private:
    Ui::loginwidow *ui;
};

#endif // LOGINWIDOW_H
