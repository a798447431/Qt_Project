#include "myform.h"
#include "ui_myform.h"
#include <QWebChannel>
#include "webobject.h"
#include <QtWidgets>
#include <QWebEngineView>
#include <QtWebChannel/QtWebChannel>
#include "bridge.h"

MyForm::MyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyForm)
{
     ui->setupUi(this);
//     m_dataObj = new WebObject();
//     m_vboxlayout = new QVBoxLayout;
//     m_webview =new QWebEngineView(ui->widget);
//     m_vboxlayout->addWidget(m_webview);
//      ui->widget->setLayout(m_vboxlayout);
     webview =new QWebEngineView();
     webview->setParent(this);
     ui->gridLayout->addWidget(webview);

     webview->page()->load(QUrl("qrc:/Resources/web/index.html"));

//      QWebChannel *channel = new QWebChannel(this);
//      channel->registerObject("bridge", (QObject*)bridge::instance());
//      webview->page()->setWebChannel(channel);

//     m_webview->page()->load(QUrl("qrc:/Resources/web/index.html"));

//       m_webview->page()->load(QUrl("qrc:/Resources/web/testEcharts.html"));




    m_dataObj = new WebObject();

    //重要设置
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("person",m_dataObj);
    webview->page()->setWebChannel(channel);
//    webview->page()->load(QUrl("qrc:/Resources/web/index.html"));


//    QFile file;
//    file.setFileName(":/jquery.min.js");
//    file.open(QIODevice::ReadOnly);
//    jQuery = file.readAll();
//    jQuery.append("\n var qt =  jQuery.noConflict(true) ;");
//    file.close();


}

MyForm::~MyForm()
{
    delete ui;
}

//获取GUI文本框中的数据，更新网页数据
void MyForm::on_okBtn_clicked()
{
    bool ok;
    QString name = ui->nameEdit->text().trimmed();
    int age = ui->ageEdit->text().trimmed().toInt(&ok, 10);
    if (!ok)
    {
        age = 0;
    }
    //更新网页数据
    m_dataObj->setName(name);
    m_dataObj->setAge(age);
}


//调用或运行js脚本
void MyForm::on_pushButton_clicked()
{
    qDebug() << "debug" ;
    //运行js脚本
    QString code;
    code = "alert('p')";
    webview->page()->runJavaScript(code);
    //调用js脚本
    webview->page()->runJavaScript("showAlert()");
}

//通过文本框中的内容形成js脚本并运行
void MyForm::on_callJsBtn_clicked()
{
        //执行网页 JS
        QString strJs = ui->jsEdit->toPlainText();
        webview->page()->runJavaScript(strJs);
}

//
