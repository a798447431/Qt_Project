#include "headerview.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
HeaderView::HeaderView(Qt::Orientation orientation, QWidget*  parent)
    : QHeaderView(orientation, parent)
{
       isOn=false;

}

void HeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if(logicalIndex == 0)
    {
        QStyleOptionButton option;
        option.iconSize = QSize(10,10);
       // option.rect = rect;
        option.rect = QRect(2,5,20,20);






        if(isOn)
            option.state = QStyle::State_On;
        else
            option.state = QStyle::State_Off;
        this->style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
//        QPoint topLeft = option.rect.topLeft();
//        QPoint bottomRight = option.rect.topRight();
//        QLinearGradient backgroundGradient(topLeft, bottomRight);
//        backgroundGradient.setColorAt(0.0, QColor(Qt::white).lighter(10));
//        backgroundGradient.setColorAt(1.0, Qt::white);
//        painter->fillRect(option.rect, QBrush(backgroundGradient));

    }
}


//void HeaderView::mousePressEvent(QMouseEvent *event)
//{
//  if (isOn)
//    isOn = false;
//  else
//    isOn = true;
//  this->update();
//  QHeaderView::mousePressEvent(event);
//}

void  HeaderView::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->x()>31)
        return;
    if (isOn)
      isOn = false;
    else
      isOn = true;
    this->update();
     //emit stateChanged();
    int x=event->x();
    int y=event->y();
    qDebug()<<x;
    qDebug()<<y;
    emit checkBoxStateChange(isOn);
  //  emit headerDataChanged(Qt::Orientation::Horizontal,0,0);
    this->updateSection(0);
    QHeaderView::mouseReleaseEvent(event);

}

void HeaderView::receiveQueryChange()
{
    isOn=false;
    emit checkBoxStateChange(isOn);
     this->updateSection(0);
   // emit headerDataChanged(Qt::Orientation::Horizontal,0,0);

}


