#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(updateTimeAndDisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTimeAndDisplay() {
    QTime current = QTime::currentTime();
    int t = this->baseTime.msecsTo(current);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    showStr = showTime.toString("hh:mm:ss:zzz");
    this->ui->lcdNumber->display(showStr);
    //this->baseTime= this->baseTime.addMSecs(1);
    //QString showStr = this->baseTime.toString("hh:mm:ss:zzz");
    //this->ui->lcdNumber->display(showStr);
}

void MainWindow::on_btn_start_clicked()
{
    this->baseTime = QTime::currentTime();
    this->ptimer->start(1);
    this->ui->btn_start->setEnabled(false);
}

void MainWindow::on_btn_stop_clicked()
{
   if (this->ui->btn_stop->text() == "停止") {
       this->ui->btn_stop->setText("清零");
       this->ptimer->stop();
       this->ui->btn_start->setEnabled(false);
       this->ui->btn_pause->setEnabled(false);
   } else {
       this->ui->lcdNumber->display("00:00:00:000");
       this->ui->textBrowser->clear();
       this->ui->btn_stop->setText("停止");
       this->ui->btn_start->setEnabled(true);
       this->ui->btn_pause->setEnabled(true);
   }
}

void MainWindow::on_btn_pause_clicked()
{
    static QTime pauseTime;
    if (this->ui->btn_pause->text() == "暂停") {
        pauseTime = QTime::currentTime();
        this->ptimer->stop();
        this->ui->btn_start->setEnabled(false);
        this->ui->btn_stop->setEnabled(false);
        this->ui->btn_pause->setText("继续");
    } else {
        QTime cut = QTime::currentTime();
        int t = pauseTime.msecsTo(cut);
        this->baseTime = this->baseTime.addMSecs(t);
        this->ptimer->start(1);
        this->ui->btn_pause->setText("暂停");
        this->ui->btn_start->setEnabled(true);
        this->ui->btn_stop->setEnabled(true);
    }
}

void MainWindow::on_btn_log_clicked()
{
    this->ui->textBrowser->append(this->showStr);
}
