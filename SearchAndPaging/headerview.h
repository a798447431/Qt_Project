#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QHeaderView>

class HeaderView : public QHeaderView
{

    Q_OBJECT
public:
    //构造函数， 第一个参数设定表头方向
    HeaderView(Qt::Orientation orientation, QWidget* parent = 0);

signals:

    void checkBoxStateChange(bool isOn);

public slots:
    void receiveQueryChange();

protected:
    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const;

   // void mousePressEvent(QMouseEvent* event);
      void mouseReleaseEvent(QMouseEvent *event);
public:
    //checkbox的开启或关闭状态
    bool isOn;
};






#endif // HEADERVIEW_H
