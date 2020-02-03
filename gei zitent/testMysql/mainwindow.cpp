#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include<QException>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try
    {
    qDebug()<<QCoreApplication::libraryPaths ();
    qDebug() << QSqlDatabase::drivers();

    ///add mysql db
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("examsg");
    db.setHostName("127.0.0.1");
   db.setPassword("root");
    db.setUserName("root");

    bool isok = db.open();
    if(isok)
    {
        qDebug() <<" open";
        QMessageBox::warning(this,"mysql status","open");
        QSqlQuery sql ;
        sql.exec("create table test(id int primary key);");
    }
    else
    {
        qDebug() <<"not open";
    }
    }
    catch(QException &ex)
    {
        qDebug() << ex.what();
    }
    /*
    *open database
    */
//    if(db.open())
//    {
        //QMessageBox::warning(this,"waring","open");

//    }
//    else
//    {
//        QMessageBox::warning(this,"waring","not open");

//    }
//qDebug() << "QSqlDatabase::2()";

}

MainWindow::~MainWindow()
{
    delete ui;
}
