#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domxml.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);

    qDebug() << "1";
    domXML::createXML("../dom.xml");
    qDebug() << "2";
    QStringList list;
    list.insert(0,"111");
    domXML::appendXML("../dom.xml",list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
