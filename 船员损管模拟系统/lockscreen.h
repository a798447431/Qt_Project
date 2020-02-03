#ifndef LOCKSCREEN_H
#define LOCKSCREEN_H

#include <QDialog>

namespace Ui {
class lockscreen;
}

class lockscreen : public QDialog
{
    Q_OBJECT

public:
    explicit lockscreen(QWidget *parent = nullptr);
    ~lockscreen();

private:
    Ui::lockscreen *ui;
};

#endif // LOCKSCREEN_H
