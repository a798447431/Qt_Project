#ifndef SINGLETON_H
#define SINGLETON_H

#include <QString>
#include <QList>
#include <QMap>

//单例模式 具体讲解：https://www.cnblogs.com/sunchaothu/p/10389842.html
//单例模式只提供唯一一个类的实例,具有全局变量的特点，在任何位置都可以通过接口获取到那个唯一实例
//简单用来存储在不同窗口之间都要调用的信息，我用其存储了用户的登录帐号信息和用户管理窗口中用户在复选框中勾选的条目信息

class SingleTon
{
public:
    static SingleTon* GetInstance(); //单例模式的获取方法，设置为类方法
    static void Release();

    QString get_Nowinfo() { //获取用户登录帐号信息
        return now_info;
    }
    void set_Nowinfo(QString str) { //设置用户登录帐号信息
        now_info = str;
    }
    void insert_map_info(int row, QString str) { //插入用户管理窗口中用户在复选框中勾选的条目信息
        map.insert(row, str); //根据复选框传入的行信息作为key值，用户的帐号信息作为value值，插入到map中
    }
    void delete_map_info(int row) { //复选框取消勾选时删除map中对应的行的信息
        map.remove(row);
    }
    bool isEmpty_map() { //判断map是否为空
        return map.isEmpty();
    }
    void clear_map() { //清空map
        return map.clear();
    }
    QList<QString> return_map_info() { //将map内存储的value值以QList形式返回
        return map.values();
    }
    int return_map_count() { //返回map中的数据总数
        return map.count();
    }

private:
    SingleTon(); //单例模式的特点，构造函数私有化
    static SingleTon *m_pInstance; //生成单例模式对象
    QMap<int, QString> map; //map数据结构，用来存储用户管理窗口中用户在复选框中勾选的条目信息
    QString now_info;  //字符串，用来存储用户的登录帐号信息
};

#endif // SINGLETON_H
