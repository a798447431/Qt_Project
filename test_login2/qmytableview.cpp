#include "qmytableview.h"
#include "singleton.h"

QMyTableView::QMyTableView(QWidget *parent):QTableView(parent)
{
}

void QMyTableView::mousePressEvent(QMouseEvent * event)
{
   int xPos = event->x();
   int yPos = event->y();
   QModelIndex idx = indexAt(QPoint(xPos, yPos));
   if(!idx.isValid( )) {
       SingleTon::GetInstance()->clear_list();
   }
   QTableView::mousePressEvent(event);
}

