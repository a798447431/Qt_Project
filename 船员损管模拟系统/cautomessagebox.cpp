#include "cautomessagebox.h"

//自定义信息框，只是简单的添加了更改窗口大小的函数，使用会有窗口位置有时显示在左上角的BUG，并且使用起来比较麻烦
//网上有更好的实现方法，我当前能力不足还没法实现

CAutoMessageBox::CAutoMessageBox(QWidget *parent):QMessageBox(parent),_width(0),_high(0) //初始化列表 将窗口长宽默认设置为0
{

}

void CAutoMessageBox::AutoSetSize(int width, int high) { //将自己设置的窗口大小的值传给类的私有成员
    _width = width;
    _high = high;
}

void CAutoMessageBox::resizeEvent(QResizeEvent *event) { //通过resizeEvent事件对窗口大小进行修改
    setFixedSize(_width, _high);
}
