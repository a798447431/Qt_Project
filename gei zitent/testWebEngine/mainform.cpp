#include "mainform.h"
#include "ui_mainform.h"
#include <QtWidgets>
#include <QWebEngineView>
#include <QtWebChannel/QtWebChannel>
#include<QLabel>
MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);



    //    QWebEngineView * pv = new QWebEngineView();
    //    pv->setUrl(QUrl("http://www.baidu.com"));
    //    pv->show();
    //    pv->page()->setDevToolsPage(pdev->page());

}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_pushButton_clicked()
{

    //    QUrl url;
    //    url = QUrl("http://www.baidu.com");
    //    view = new QWebEngineView(this);
    //    view->load(url);
    //    view->show();
    //    ui->gridLayout->addWidget(view);
    //    setCentralWidget(view);
    pv = new QWebEngineView();

    pv->setUrl(QUrl("qrc:/Resources/web/login.html"));
    pv->setParent(this);

    ui->gridLayout->addWidget(pv);

    QLabel *q = new QLabel("Start");

    ui->gridLayout->addWidget(q);



}

void MainForm::on_pushButton_2_clicked()
{

}
