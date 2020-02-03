#include "webobject.h"
#include <QDebug>

WebObject::WebObject(QObject *parent) : QObject(parent)
{
    m_name = "owenlang";
    m_age = 26;
}

void WebObject::setName(const QString &name)
{
    if (name != m_name)
    {
        m_name = name;
        emit sig_nameChanged(m_name);
    }
}

void WebObject::setAge(int age)
{
    if (age != m_age)
    {
        m_age = age;
        emit sig_ageChanged(m_age);
    }
}

//供JS调用的 Qt 的函数
void WebObject::slot_debug(const QString& msg)
{
    qDebug() << "web debug: " << msg;
}


//接收前端调用
void WebObject::JSSendMessage(QString user,QString pwd)
{
    qDebug() <<"user:" << user;
    qDebug() <<"pwd:" << pwd;
    //发送信号回前台
    emit SigSendMessageToJS("ok");
}

