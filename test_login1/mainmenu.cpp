#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "singleton.h"
#include "cautomessagebox.h"
#include <QDebug>
//#include <QAbstractItemModel>
//#include <QModelIndex>
//#include <QVariant>
#include <QDateTime>
#include "database.h"

mainmenu::mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    this->pModel = new sqltablemodel(this, database::GetQSqlDatabase());
    currentPage = 1;
    m_pTimer = new QTimer(this);
    m_pTimer->setSingleShot(true);
    QTimer *timer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(init_system()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
    //timerUpdate();
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::start_timer() {
    m_pTimer->start(100);
    return ;
}

void mainmenu::init_system() {
    init_show_sqlinfo();
    update_pagenum();
    init_system_state();
    return ;
}

void mainmenu::on_btn_registe_clicked() {
    this->r.show();
    return ;
}

void mainmenu::on_btn_exit_clicked(){
    CAutoMessageBox msg;
    msg.AutoSetSize(400, 200);
    msg.setText(tr("确定要退出用户管理平台吗?"));
    msg.setWindowTitle(tr("退出"));
    msg.setIcon(QMessageBox::Question);
    msg.addButton(tr("确定"),QMessageBox::AcceptRole);
    msg.addButton(tr("返回"),QMessageBox::RejectRole);
    if(msg.exec() == QMessageBox::AcceptRole) {
        this->close();
    } else {
        return ;
    }
}

void mainmenu::init_tableview() {
    this->ui->tableView->setModel(pModel);
    pModel->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    pModel->setHeaderData(1, Qt::Horizontal, tr("帐号"));
    pModel->setHeaderData(2, Qt::Horizontal, tr("系统角色"));
    pModel->setHeaderData(3, Qt::Horizontal, tr("性别"));
    pModel->setHeaderData(4, Qt::Horizontal, tr("机构"));
    pModel->setHeaderData(5, Qt::Horizontal, tr("机构代码"));
    pModel->setHeaderData(6, Qt::Horizontal, tr("职务"));
    pModel->setHeaderData(7, Qt::Horizontal, tr("职务代码"));
    //自动调整宽度
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableView->show();
    return ;
}

void mainmenu::on_btn_minimize_clicked()
{
    QWidget::showMinimized();
    return ;
}

void mainmenu::on_btn_changpwd_clicked()
{
    this->cp.show();
    return ;
}

void mainmenu::on_btn_findinfo_clicked()
{
    pModel->clear();
    QString find_username = this->ui->le_find_username->text();
    QString find_usersex = this->ui->cb_find_usersex->currentText();
    QString find_organization = this->ui->le_find_organization->text();
    QString find_organization_code = this->ui->le_find_organization_code->text();
    QString find_duty = this->ui->le_find_duty->text();
    QString find_duty_code = this->ui->le_find_duty_code->text();
    QString sql_search = "select username, account_num, system_role, usersex, organization, organization_code, duty, duty_code from info.userinfo where 1 = 1";
    if (find_username != "") {
        sql_search += " AND username LIKE '%" + find_username  + "%'";
    }
    if (find_usersex != "") {
        sql_search += " AND usersex = '" + find_usersex + "'";
    }
    if (find_organization != "") {
        sql_search += " AND organization LIKE '%" + find_organization + "%'";
    }
    if (find_organization_code != "") {
        sql_search += " AND organization_code = '" + find_organization_code + "'" ;
    }
    if (find_duty != "") {
        sql_search += " AND duty LIKE '%" + find_duty + "%'";
    }
    if (find_duty_code != "") {
        sql_search += " AND duty_code = '" + find_duty_code + "'";
    }
    //qDebug() << sql_search;
    pModel->setFilter(sql_search);
    pModel->select();
    this->ui->tableView->setModel(pModel);
    init_tableview();
    return ;
}

void mainmenu::on_btn_resetting_clicked()
{
    this->ui->le_find_username->clear();
    this->ui->cb_find_usersex->setCurrentIndex(0);
    this->ui->le_find_organization->clear();
    this->ui->le_find_organization_code->clear();
    this->ui->le_find_duty->clear();
    this->ui->le_find_duty_code->clear();
    pModel->clear();
    init_show_sqlinfo();
    return ;
}

void mainmenu::init_show_sqlinfo() {
    QString init_sql = "select username, account_num, system_role, usersex, organization, organization_code, duty, duty_code from info.userinfo where 1 = 1";
    pModel->setFilter(init_sql);
    pModel->select();
    this->ui->tableView->setModel(pModel);
    init_tableview();
    return ;
}

/*
void mainmenu::on_tableView_clicked(const QModelIndex &index)
{
    QVariant datatmp;
    qDebug() << stm.setData(index, datatmp, 0);
}
*/

void mainmenu::on_btn_delete_clicked()
{
    CAutoMessageBox msg;
    if (SingleTon::GetInstance()->rowList_size() == 0) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("没有选中要删除的条目！"));
        msg.setWindowTitle(tr("删除"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    } else {
        int curRow = ui->tableView->currentIndex().row();
        pModel->removeRow(curRow);
        msg.AutoSetSize(400, 200);
        msg.setText(tr("是否要删除此信息？"));
        msg.setWindowTitle(tr("删除信息"));
        msg.setIcon(QMessageBox::Question);
        msg.addButton(tr("确定"),QMessageBox::AcceptRole);
        msg.addButton(tr("取消"),QMessageBox::RejectRole);
        if(msg.exec() == QMessageBox::AcceptRole) {
            pModel->submitAll();
        } else {
            pModel->revertAll();
        }
    }
    return ;
}

void mainmenu::on_btn_edit_clicked()
{
    CAutoMessageBox msg;
    if (SingleTon::GetInstance()->rowList_size() == 0) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("没有选中帐号，请重试！"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else {
        this->ci.show();
        ci.start_timer();
    }
}

void mainmenu::on_btn_pageup_clicked()
{
    pg.pageUp(this->ui->tableView);
    if (currentPage > 1) currentPage -= 1;
    update_pagenum();
}

void mainmenu::on_btn_pagedown_clicked()
{
    pg.pageDown(this->ui->tableView);
    if (currentPage < pg.pageCount(this->ui->tableView)) {
        currentPage += 1;
    }
    update_pagenum();
}

void mainmenu::update_pagenum() {
    this->ui->lb_now_page_num->setText(QString("第%1页-共%2页").arg(currentPage).arg(pg.pageCount(this->ui->tableView)));
}

void mainmenu::on_btn_pagehome_clicked()
{
    currentPage = 1;
    pg.pageHome(this->ui->tableView);
    update_pagenum();
}

void mainmenu::on_btn_end_clicked()
{
    currentPage = pg.pageCount(this->ui->tableView);
    pg.pageEnd(this->ui->tableView);
    update_pagenum();
}

void mainmenu::on_btn_lockscreen_clicked()
{
    this->ls.exec();
}

void mainmenu::timerUpdate() {
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    this->ui->lb_system_time->setText(str);
    return ;
}

void mainmenu::init_system_state() {
    QString temp_info = QString("select * from info.userinfo where account_num='%1'").arg(SingleTon::GetInstance()->get_Nowinfo());
    QString tmp_info_systemrole = nullptr;
    QString tmp_info_username = nullptr;
    QSqlQuery query;
    query.exec(temp_info);
    if (query.first()) {
        tmp_info_systemrole = query.value(2).toString();
        tmp_info_username = query.value(3).toString();
    }
    this->ui->lb_system_username->setText(QString("当前登录者：%1").arg(tmp_info_username));
    this->ui->lb_system_role->setText(QString("系统角色：%1").arg(tmp_info_systemrole));
    this->ui->lb_system_state->setText(QString("当前系统状态：无"));
    return ;
}


void mainmenu::on_btn_return_clicked()
{
    emit SignFather();
}
