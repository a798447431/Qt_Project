#ifndef SINGLETON_H
#define SINGLETON_H

#include <QString>
#include <QList>

class SingleTon
{
public:
    static SingleTon* GetInstance();
    static void Release();
    void set_rowList(QString str);
    QString get_rowList(int i);
    int rowList_size();
    void remove_rowList();
    QString get_Nowinfo() {
        return now_info;
    }
    void set_Nowinfo(QString str) {
        now_info = str;
    }

private:
    SingleTon();
    static SingleTon *m_pInstance;
    QList<QString> rowList;
    QString now_info;
};

#endif // SINGLETON_H
