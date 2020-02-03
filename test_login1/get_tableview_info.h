#ifndef GET_TABLEVIEW_INFO_H
#define GET_TABLEVIEW_INFO_H

#include <QObject>

class get_tableview_info : public QObject
{
    Q_OBJECT

public:
    static get_tableview_info * getInfo();
    void addTempInfo();

private:
    explicit get_tableview_info(QObject *parent = nullptr);

signals:
    void getTempInfo();

public slots:

private:
    static get_tableview_info *gti;
};

#endif // GET_TABLEVIEW_INFO_H
