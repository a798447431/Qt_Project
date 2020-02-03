#ifndef CAUTOMESSAGEBOX_H
#define CAUTOMESSAGEBOX_H

#include <QMessageBox>
#include <QWidget>
#include <QResizeEvent>

class CAutoMessageBox : public QMessageBox
{
public:
    explicit CAutoMessageBox(QWidget *parent=0);
    ~CAutoMessageBox(){}

public:
    void AutoSetSize(int width, int high);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    int _width;
    int _high;
};

#endif // CAUTOMESSAGEBOX_H
