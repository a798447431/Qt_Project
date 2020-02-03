#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class bridge : QObject
{
Q_OBJECT
public:
    static bridge* instance();

public slots:
    void showMsgBox(QString msg);

private:
    bridge();
};


#endif // BRIDGE_H
