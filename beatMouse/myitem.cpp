#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include "handler.h"
#include <QCursor>

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/picture/bg1.png"));
    this->start = false;
    this->mouse = false;
    this->setCursor(QCursor(QPixmap(":/mouse/picture/pictureUp.png")));
}

void myItem::setPic(QString path) {
    this->setPixmap(QPixmap(path));
}


void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(QPixmap(":/mouse/picture/picturedown.png")));
    if (this->isStart()) {
        handler *hand = handler::getInstance();
        if (this->isMouse()) {
            hand->addScore();
            this->setPixmap(QPixmap(":/mouse/picture/beatmouse.png"));
            this->mouse = false;
        } else {
            qDebug() << "打的不是老鼠";
        }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(QPixmap(":/mouse/picture/pictureUp.png")));
}

void myItem::setMouse(bool mouse) {
    this->mouse = mouse;
}

bool myItem::isMouse() {
    return this->mouse;
}

void myItem::setStart(bool start) {
    this->start = start;
}

bool myItem::isStart() {
    return this->start;
}
