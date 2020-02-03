#ifndef QMYTABLEVIEW_H
#define QMYTABLEVIEW_H

#include <QTableView>
#include <QMouseEvent>
#include <QModelIndex>
#include <QString>
#include <QDebug>

class QMyTableView : public QTableView
{
public:
    QMyTableView(QWidget *parent=0);

private:
    void mousePressEvent(QMouseEvent * event);
};

#endif // QMYTABLEVIEW_H
