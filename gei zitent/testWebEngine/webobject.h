#ifndef WEBOBJECT
#define WEBOBJECT
#include <QObject>

class WebObject : public QObject
{
    Q_OBJECT

    //供网页 JS 使用的属性
    Q_PROPERTY(QString name MEMBER m_name NOTIFY sig_nameChanged)
    Q_PROPERTY(int age MEMBER m_age NOTIFY sig_ageChanged)

public:
    explicit WebObject(QObject *parent = 0);

    void setName(const QString& name);
    void setAge(int age);

signals:
    void sig_nameChanged(const QString& name);
    void sig_ageChanged(int age);

    void SigSendMessageToJS(QString result);

public slots:
    //供网页 JS 调用
    void slot_debug(const QString& msg);

    void JSSendMessage(QString user,QString pwd);
private:
    QString m_name;
    int m_age;
};
#endif // WEBOBJECT

