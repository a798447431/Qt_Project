#ifndef DOMXML_H
#define DOMXML_H
#include <QString>
#include <QStringList>

#include <QDomElement>
#include <QDomDocument>


class domXML
{
public:
    domXML();

    static void createXML(QString path);
    static void appendXML(QString path,QStringList list);

    static void writeXML(QDomDocument &doc,QDomElement &root,QStringList list);
    static void readXML(QString &filepath,QStringList &list );
};

#endif // DOMXML_H
