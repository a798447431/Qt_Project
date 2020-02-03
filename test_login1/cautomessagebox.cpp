#include "cautomessagebox.h"

CAutoMessageBox::CAutoMessageBox(QWidget *parent):QMessageBox(parent),_width(0),_high(0)
{

}

void CAutoMessageBox::AutoSetSize(int width, int high) {
    _width = width;
    _high = high;
}

void CAutoMessageBox::resizeEvent(QResizeEvent *event) {
    setFixedSize(_width, _high);
}
