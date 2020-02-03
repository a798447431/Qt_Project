#ifndef SINGLETON_H
#define SINGLETON_H

#include <QString>
#include <QList>

class SingleTon
{
public:
    static SingleTon* GetInstance();
    static void Release();
    void append_list(QString str) {
        list.append(str);
    }
    QString get_list_str(int i) {
        return list.at(i);
    }
    QString get_Nowinfo() {
        return now_info;
    }
    void set_Nowinfo(QString str) {
        now_info = str;
    }
    void clear_list() {
        list.clear();
    }
    int isEmpty_list() {
        if (!list.isEmpty()) return 0;
        else return 1;
    }
    int return_list_size() {
        return list.size();
    }
    QString return_list_end() {
        return list.at(list.size() - 1);
    }

private:
    SingleTon();
    static SingleTon *m_pInstance;
    QList<QString> list;
    QString now_info;
};

#endif // SINGLETON_H
