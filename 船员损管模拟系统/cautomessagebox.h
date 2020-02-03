#ifndef CAUTOMESSAGEBOX_H
#define CAUTOMESSAGEBOX_H

#include <QMessageBox> //信息提示框，为了实现改变信息框大小的功能，对其进行简单重构
#include <QWidget> //QWidget类是所有用户界面对象的基类，通过该类对QMessageBox的大小进行修改
#include <QResizeEvent> //QResizeEvent类是所有窗口大小、位置及其大小改变引起的事件类，通过该类在每次显示窗口事件的时候修改窗口的大小

class CAutoMessageBox : public QMessageBox
{
public:
    explicit CAutoMessageBox(QWidget *parent=0);
    ~CAutoMessageBox(){}

public:
    void AutoSetSize(int width, int high); //设置QMessageBox大小的函数

protected:
    void resizeEvent(QResizeEvent *event);

private:
    int _width;
    int _high;
};

#endif // CAUTOMESSAGEBOX_H
