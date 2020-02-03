#include "domxml.h"
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDomProcessingInstruction>
#include <QDebug>
#include <QTextStream>
#include <QDateTime>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

domXML::domXML()
{


}
void domXML::createXML(QString path)
{

    QFile file(path) ;
    if(file.exists())
    {
        cout << "file exist!";
        return;
    }
    else//no exist
    {

        //write type
        bool isok = file.open(QIODevice::WriteOnly);
        //open success
        if(isok == true)
        {
            //create xml document
            QDomDocument doc;
            QDomProcessingInstruction ins;
            ins = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'utf-8\'");
            doc.appendChild(ins);
            //gen
            QDomElement root = doc.createElement("test");
            doc.appendChild(root);
            //save
            QTextStream stream(&file);
            doc.save(stream,4);
            file.close();

        }
        else
        {
            cout << "xml file write error!";
            return;
        }

    }

}
void domXML::appendXML(QString path,QStringList list)
{

    QFile file(path) ;
    bool isok = file.open(QIODevice::ReadOnly);

    //open success
    if(isok == true)
    {
        //create xml document
        QDomDocument doc;
        isok = doc.setContent(&file);

        if(isok)
        {
            file.close();

            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yyyy-MM-dd");
            //get root
            QDomElement root = doc.documentElement();
            if(root.hasChildNodes())//if have sub node
            {


            }
            else//not have sub node
            {
                QDomElement subnode1 = doc.createElement("node1");

                //                subnode1.attributeNode("date1");

                QDomAttr attr = doc.createAttribute("date2");
                attr.setValue(dateStr);
                subnode1.setAttributeNode(attr);
                root.appendChild(subnode1);
            }

        }

        //save
        isok = file.open(QIODevice::WriteOnly);
        if(isok)
        {
            QTextStream stream(&file);
            doc.save(stream,4);
            file.close();
        }

    }
    else
    {
        cout << "xml file write error!";
        return;
    }



}

//
void domXML::writeXML(QDomDocument &doc,QDomElement &root,QStringList list)
{


}

//read xml
void domXML::readXML(QString &filepath,QStringList &list )
{


    QFile file(filepath);

    bool isok = file.open(QIODevice::ReadOnly);
    QDomDocument doc;
    doc.setContent(&file);
    if(isok)
    {
        QDomElement root = doc.documentElement();
        file.close();

        if(root.hasChildNodes())
        {
            QDomElement lastele = root.lastChildElement();
            QDomNodeList nodelist = root.childNodes();
            for(int i=0 ; i <nodelist.size(); i++)
            {
                QDomNodeList subNodes =  nodelist.at(i).toElement().childNodes();
            }
        }
    }
}






//void writeXML() { QString strFile("Blogs.xml"); QFile file(strFile); if (!file.open(QFile::WriteOnly | QFile::Text)) { // 只写模式打开文件
//        qDebug() << QString("Cannot write file %1(%2).").arg(strFile).arg(file.errorString()); return; } QXmlStreamWriter writer(&file);
//                  // writer.setCodec("GBK");
//                  // XML 编码
//                  writer.setAutoFormatting(true);
//                                // 自动格式化
//                                writer.writeStartDocument("1.0", true);
//                                              // 开始文档（XML 声明）
//                                              writer.writeComment(QString::fromLocal8Bit("纯正开源之美，有趣、好玩、靠谱。。。"));
//                                                            // 注释
//                                                            writer.writeProcessingInstruction("xml-stylesheet type=\"text/css\" href=\"style.css\""); // 处理指令

//                                                                          // DTD
//                                                                          writer.writeDTD(QString::fromLocal8Bit("<!DOCTYPE Blogs [ <!ENTITY Copyright \"Copyright 2016《Qt实战一二三》\"> <!ELEMENT Blogs (Blog)> <!ELEMENT Blog (作者,主页,个人说明)> <!ELEMENT 作者 (#PCDATA)> <!ELEMENT 主页 (#PCDATA)> <!ELEMENT 个人说明 (#PCDATA)> ]>"));
//                                                                                        writer.writeStartElement("Blogs"); // 开始根元素 <Blogs>
//                                                                                                      writer.writeAttribute("Version", "1.0"); // 属性
//                                                                                                                    writer.writeStartElement("Blog"); // 开始子元素 <Blog>
//                                                                                                                                  writer.writeTextElement(QString::fromLocal8Bit("作者"), QString::fromLocal8Bit("一去丶二三里"));
//                                                                                                                                                writer.writeTextElement(QString::fromLocal8Bit("主页"), "http://blog.csdn.net/liang19890820");
//                                                                                                                                                              writer.writeTextElement(QString::fromLocal8Bit("个人说明"), QString::fromLocal8Bit("青春不老，奋斗不止！"));
//                                                                                                                                                                            writer.writeEntityReference("Copyright"); writer.writeCDATA(QString::fromLocal8Bit("<Qt分享&&交流>368241647</Qt分享&&交流>"));
//                                                                                                                                                                            writer.writeCharacters(">"); writer.writeEmptyElement(QString::fromLocal8Bit("Empty")); // 空元素
//                                                                                                                                                                            writer.writeEndElement(); // 结束子元素 </Blog>
//                                                                                                                                                                                          writer.writeEndElement(); // 结束根元素 </Blogs>
//                                                                                                                                                                                                        writer.writeEndDocument(); // 结束文档
//                                                                                                                                                                                                                      file.close(); // 关闭文件
//                }
