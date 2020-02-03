#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "singleton.h"
#include "cautomessagebox.h"
#include <QAbstractItemModel> //QAbstractItemModel类为自定义模型提供接口
#include <QModelIndex> //QModelIndex类用于定位数据模型中的数据
#include <QVariant> //QVariant类充当着最常见的数据类型的联合,可以保存很多Qt的数据类型
#include <QDateTime>

mainmenu::mainmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainmenu)
{
    /*
     * 用户管理窗口成员变量初始化设置
    */
    ui->setupUi(this);
    this->model = new MyQSqlQueryModel; // 初始化model对象
    currentPage = 1; //初始化当前页数为1
    m_pTimer = new QTimer(this); //初始化定时器对象，用来发送信号，触发初始化TableView信息的函数
    m_pTimer->setSingleShot(true); //设置定时器信号只触发一次
    QTimer *timer = new QTimer(this); //这个定时器对象用来更新系统状态栏的时间信息
    this->ui->tableView->setHorizontalHeader(new HeaderViewPrivate(Qt::Horizontal)); //创建TableView列头

    connect(qobject_cast<HeaderViewPrivate *>(this->ui->tableView->horizontalHeader()), &HeaderViewPrivate::checked, [&](bool ischecked) {
        if (ischecked) checkbox_select_all(); //如果复选框被选中 执行checkbox_select_all()函数
        else checkbox_deselect_all(); //否则执行checkbox_deselect_all()函数
    });//链接信号与槽函数，将表头中的复选框的点击信号与HeaderViewPrivate类中ischeck()函数绑定

    /*
     * 链接信号与槽函数，将cancle_checkbox_select()信号与HeaderViewPrivate类中ischeck函数绑定unchackedbox()函数绑定
     * 如果发送cancle_checkbox_select()信号，则表头的复选框会被取消勾选
    */
    connect(this, SIGNAL(cancle_checkbox_select()), qobject_cast<HeaderViewPrivate *>(this->ui->tableView->horizontalHeader()), SLOT(unchackedbox()));

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(init_system())); //链接信号与槽函数，将定时器m_pTimer的timeout()信号与init_system()槽函数进行绑定
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate())); //链接信号与槽函数，将定时器timer的timeout()信号与timerUpdate()槽函数进行绑定
    connect(this->model, SIGNAL(sign_checked(int)), this, SLOT(slotCheckBoxCheck(int)));//链接信号与槽函数，将model的sign_checked(int)信号与slotCheckBoxCheck(int)槽函数进行绑定
    connect(this->model, SIGNAL(sign_unchecked(int)), this, SLOT(slotCheckBoxUncheck(int)));//链接信号与槽函数，将model的sign_unchecked(int)信号与slotCheckBoxUncheck(int)槽函数进行绑定
    timer->start(1000); //设置定时器timer的触发时间为1秒(1000毫秒)
    this->ui->tableView->verticalScrollBar()->installEventFilter(this); //将TableView的滚动条与事件过滤器进行绑定，用来禁用鼠标滚轮
}

mainmenu::~mainmenu()
{
    delete ui;
    delete m_pTimer;
}

void mainmenu::start_timer()
{
    m_pTimer->start(100);//设置m_pTimer定时器的触发时间为0.1秒，使得刚进入此窗口时就触发槽函数
    return ;
}

void mainmenu::init_system() { //初始化此窗口全部信息的函数
    init_show_sqlinfo(); //初始化tableview的默认显示信息
    update_pagenum(); //更新当前的页数
    init_system_state(); //初始化系统状态栏
    return ;
}

void mainmenu::on_btn_registe_clicked()
{
    this->r.show(); //显示新建用户窗口
    return ;
}

void mainmenu::on_btn_exit_clicked(){ //退出用户信息管理窗口
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

void mainmenu::init_tableview() { //初始化tableview的表头信息
    /*
     * 用setHeaderData()函数设置QSqlQueryModel类的对象model模型的表头信息
     * setHeaderData()的第一个参数为列数，表示为第几列设置表头
     * setHeaderData()的第二个参数为分割线，不需要修改
     * setHeaderData()的第三个参数为表头名称，修改tr内的内容就可以修改表头名称
    */
    this->model->setHeaderData(0, Qt::Horizontal, tr("")); //这个tr内部为空是为了容纳表头的复选框
    this->model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    this->model->setHeaderData(2, Qt::Horizontal, tr("帐号"));
    this->model->setHeaderData(3, Qt::Horizontal, tr("系统角色"));
    this->model->setHeaderData(4, Qt::Horizontal, tr("性别"));
    this->model->setHeaderData(5, Qt::Horizontal, tr("机构"));
    this->model->setHeaderData(6, Qt::Horizontal, tr("机构代码"));
    this->model->setHeaderData(7, Qt::Horizontal, tr("职务"));
    this->model->setHeaderData(8, Qt::Horizontal, tr("职务代码"));

    /*
     * tableView的setColumnWidth()函数用来每一列的宽度
     * setColumnWidth()的第一个参数为列数
     * setColumnWidth()的第二个参数为列宽
    */
    this->ui->tableView->setColumnWidth(0, 110);
    this->ui->tableView->setColumnWidth(1, 230);
    this->ui->tableView->setColumnWidth(2, 230);
    this->ui->tableView->setColumnWidth(3, 230);
    this->ui->tableView->setColumnWidth(4, 110);
    this->ui->tableView->setColumnWidth(5, 230);
    this->ui->tableView->setColumnWidth(6, 230);
    this->ui->tableView->setColumnWidth(7, 230);
    this->ui->tableView->setColumnWidth(8, 230);

    //自动调整宽度
    //this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); //设置表头不可以被拖动
    this->ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //设置tableview中只能选中整行
    this->ui->tableView->horizontalHeader()->setStretchLastSection(true); //setStretchLastSection()函数表示将最后一列填充满表格
    this->ui->tableView->horizontalHeader()->setHighlightSections(false); //去掉表头高亮
    this->ui->tableView->verticalHeader()->setVisible(true); //显示表格表头，就是每条条目前都显示数字表示第几条
    this->ui->tableView->setShowGrid(true); //显示背景网格线
    this->ui->tableView->setFrameShape(QFrame::NoFrame); //设置边框
    this->ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置tableview中的条目不能多选
    return ;
}

void mainmenu::on_btn_minimize_clicked() { //窗口最小化
    QWidget::showMinimized();
    return ;
}

void mainmenu::on_btn_changpwd_clicked() {
    this->cp.show(); //显示修改密码窗口
    return ;
}

void mainmenu::on_btn_findinfo_clicked() { //查找信息槽函数
    this->model->clear(); //查找前先清空model数据模型
    /*
     * 查找信息流程
     * 1.获取QLine内用户输入的信息，将其保存到字符串中
     * 2.拼接sql语句，用QSqlQuery内的exec()方法判断是否查找到信息
     * 3.如果一条有关信息都没搜索到，就弹出信息框提示用户重新输入信息
     * 4.如果有一条及以上的信息，则使用model的setQuery()函数将搜索信息存入model数据模型中
     * 5.用tableview的setModel()方法将model模型中的数据显示在tableview中
    */
    QString find_username = this->ui->le_find_username->text();
    QString find_usersex = this->ui->cb_find_usersex->currentText();
    QString find_organization = this->ui->le_find_organization->text();
    QString find_organization_code = this->ui->le_find_organization_code->text();
    QString find_duty = this->ui->le_find_duty->text();
    QString find_duty_code = this->ui->le_find_duty_code->text();
    QString sql_search = "select combobox, username, account_num, system_role, usersex, organization, organization_code, duty, duty_code from info.userinfo where 1 = 1";
    //通过字符串拼接的方式进行多重信息查找
    if (find_username != "") {
        sql_search += " AND username LIKE '%" + find_username  + "%'"; //使用LIKE进行信息的模糊匹配
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
    QSqlQuery query ;
    query.exec(sql_search);
    if (!query.first()) { //如果没有搜索到任何信息
        CAutoMessageBox msg; //信息框提示
        msg.AutoSetSize(400, 200);
        msg.setText(tr("没有搜索到有关条目，请重试！"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
        init_show_sqlinfo(); //初始化tableview的显示内容
        on_btn_resetting_clicked(); //重置用户信息管理窗口内的输入信息
        return ;
    } else { //搜索到信息
        this->model->setQuery(sql_search); //使用model的setQuery()函数将搜索信息存入model数据模型中
        this->ui->tableView->setModel(model); //setModel()方法将model模型中的数据显示在tableview中
        init_tableview(); //初始化表头
        on_btn_pagehome_clicked(); //跳转到TableView第一页
        return ;
    }
}

void mainmenu::on_btn_resetting_clicked() //重置用户信息管理窗口内的全部输入信息
{
    /*
     * 1.清空QLine内信息
     * 2.设置QComboBox内数据默认显示为第0个
     * 3.清空model数据模型内信息
     * 4.初始化tableview的显示内容
    */
    this->ui->le_find_username->clear();
    this->ui->cb_find_usersex->setCurrentIndex(0); //QComboBox中setsetCurrentIndex()函数用来设置显示QComboBox中的第几个信息，从0开始计数
    this->ui->le_find_organization->clear();
    this->ui->le_find_organization_code->clear();
    this->ui->le_find_duty->clear();
    this->ui->le_find_duty_code->clear();
    this->model->clear();
    init_show_sqlinfo();
    return ;
}

void mainmenu::init_show_sqlinfo() { //初始化tableview的显示内容
    /*
     * 1.设置sql语句，该语句用来显示数据表中的全部信息
     * 2.使用model的setQuery()函数将搜索信息存入model数据模型中
     * 3.用tableview的setModel()方法将model模型中的数据显示在tableview中
     * 4.执行checkbox_deselect_all()函数，使tableview中的复选框取消勾选
     * 5.分页栏跳转到首页（其中发送了cancle_checkbox_select()信号，使表头的复选框取消勾选）
     * 6.初始化tableview的表头信息
    */
    QString init_sql = "select combobox, username, account_num, system_role, usersex, organization, organization_code, duty, duty_code from info.userinfo where 1 = 1";
    this->model->setQuery(init_sql);
    this->ui->tableView->setModel(model);
    checkbox_deselect_all();
    on_btn_pagehome_clicked();
    init_tableview();
    return ;
}

void mainmenu::on_btn_delete_clicked() //删除条目
{
    /*
     * 1.每次复选框被勾选时都将该行的行数保存下来，然后根据保存的行数获取该行的帐号信息
     * 2.将获取到的帐号信息依据行号保存在单例模式内的map数据结构中
     * 3.判断map内是否为空，如果为空，代表没有条目被勾选，弹出信息框提示
     * 4.判断map内是否只有一条信息，如果只有一条信息，则弹出信息框，用户点击确认后删除该信息
     * 5.如果map内有多条信息，则弹出信息框，用户点击确认后删除map内部全部信息
    */
    CAutoMessageBox msg;
    if(SingleTon::GetInstance()->isEmpty_map()) { //如果map内为空
        msg.AutoSetSize(400, 200);
        msg.setText(tr("没有选中要删除的条目！"));
        msg.setWindowTitle(tr("删除"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::RejectRole);
        msg.exec();
    } else if (SingleTon::GetInstance()->return_map_count() == 1){ //如果map内只有一条信息
        msg.AutoSetSize(400, 200);
        msg.setText(tr("是否要删除此信息？"));
        msg.setWindowTitle(tr("删除信息"));
        msg.setIcon(QMessageBox::Question);
        msg.addButton(tr("确定"),QMessageBox::AcceptRole);
        msg.addButton(tr("取消"),QMessageBox::RejectRole);
        if(msg.exec() == QMessageBox::AcceptRole) { //用户点击确认按钮
            QString temp_delete = QString("delete from info.userinfo where account_num='%1';").arg(SingleTon::GetInstance()->return_map_info().at(0)); //获取map内部的第一条信息并拼接到sql语句中
            this->model->setQuery(temp_delete);
            this->ui->tableView->setModel(model); //删除该条信息
            SingleTon::GetInstance()->clear_map();//清空map
            init_show_sqlinfo();
        } else {
            return ;
        }
    } else { //如果map内有多条信息
        msg.AutoSetSize(400, 200);
        msg.setText(tr("是否要删除被选中的信息？"));
        msg.setWindowTitle(tr("删除信息"));
        msg.setIcon(QMessageBox::Question);
        msg.addButton(tr("确定"),QMessageBox::AcceptRole);
        msg.addButton(tr("取消"),QMessageBox::RejectRole);
        if(msg.exec() == QMessageBox::AcceptRole) {
            QList<QString> tmp_list = SingleTon::GetInstance()->return_map_info(); //用QList数据结构读取map内存储的全部帐号信息
            for (int i = 0; i < tmp_list.count(); i++) { //for循环遍历QList内部全部帐号信息
                QString temp_delete = QString("delete from info.userinfo where account_num='%1';").arg(tmp_list.at(i));
                this->model->setQuery(temp_delete);
                this->ui->tableView->setModel(model); //依次删除每条信息
            }
            SingleTon::GetInstance()->clear_map();
            init_show_sqlinfo();
        } else {
            return ;
        }
    }
    return ;
}

void mainmenu::on_btn_edit_clicked() {//编辑用户信息
    /*
     * 编辑用户信息需要用户只勾选一个条目，不勾选或勾选多个条目都不可以
     * 1.每次复选框被勾选时都将该行的行数保存下来，然后根据保存的行数获取该行的帐号信息
     * 2.将获取到的帐号信息依据行号保存在单例模式内的map数据结构中
     * 3.判断map内是否为空，如果为空，代表没有条目被勾选，弹出信息框提示
     * 4.判断map内是否只有一条信息，如果只有一条信息，则弹出信息框，用户点击确认后发送定时器信号并显示编辑信息窗口
     * 5.判断map内是否有多条信息，有多条信息则弹出信息框提示用户
    */
    CAutoMessageBox msg;
    if (SingleTon::GetInstance()->isEmpty_map()) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("没有选中帐号，请重试！"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else if (SingleTon::GetInstance()->return_map_count() != 1) {
        msg.AutoSetSize(400, 200);
        msg.setText(tr("选中多条信息，请只选择一条信息！"));
        msg.setWindowTitle(tr("错误"));
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(tr("返回"),QMessageBox::AcceptRole);
        msg.exec();
    } else {
        this->ci.show(); //显示编辑用户信息窗口
        ci.start_timer(); //发送编辑用户信息窗口内的定时器信号，用来触发编辑用户信息窗口内的初始化信息的槽函数
    }
}

void mainmenu::on_btn_pageup_clicked() { //分页栏向上翻页
    if (!pg.pageUp(this->ui->tableView)) return ; //调用pageUp()函数向上翻页，如果tableview中没有信息，退出
    else if (pg.pageCount(this->ui->tableView) == -1) return ; //如果总页数为-1,退出
    else if (currentPage > 1) { //如果当前页数大于1
        currentPage -= 1; //每次点击上一页按钮当前页数-1
        update_pagenum(); //更新页数
    }
    checkbox_deselect_all(); //执行checkbox_deselect_all()函数，取消勾选tableview中的复选框
    emit cancle_checkbox_select(); //发送cancle_checkbox_select()信号，取消勾选表头复选框
}

void mainmenu::on_btn_pagedown_clicked() //同上
{
    if (!pg.pageDown(this->ui->tableView)) return ;
    else if (pg.pageCount(this->ui->tableView) == -1) return ;
    else if (currentPage < pg.pageCount(this->ui->tableView)) {
        currentPage += 1; //向下翻页时当前页数+1
        update_pagenum();
    }
    checkbox_deselect_all();
    emit cancle_checkbox_select();
}

void mainmenu::update_pagenum() { //更新显示当前的分页信息
    /*
     * 设置QLable显示当前页面信息，信息有当前的页数，总页数，每页显示条目数，总共条目数
    */
    this->ui->lb_now_page_num->setText(QString("第%1页-共%2页,每页%3条信息,共%4条信息").arg(currentPage).arg(pg.pageCount(this->ui->tableView)).arg(pg.pageLine(this->ui->tableView)).arg(this->model->rowCount()));
    return ;
}

void mainmenu::on_btn_pagehome_clicked() { //跳转到首页
    if (!pg.pageHome(this->ui->tableView)) return ; //调用pageHome()函数跳到首页，如果tableview中没有信息，退出
    currentPage = 1;
    update_pagenum();
    checkbox_deselect_all();
    emit cancle_checkbox_select();
}

void mainmenu::on_btn_end_clicked() {//跳转到末页
    if (!pg.pageEnd(this->ui->tableView)) return ;//调用pageEnd()函数跳到末页，如果tableview中没有信息，退出
    else currentPage = pg.pageCount(this->ui->tableView);
    update_pagenum();
    checkbox_deselect_all();
    emit cancle_checkbox_select();
}

void mainmenu::on_btn_lockscreen_clicked() { //锁屏
    this->ls.exec(); //调用exec方法显示锁屏窗口，防止对其他窗口进行操作
}

void mainmenu::timerUpdate() { //更新系统时间，同系统主窗口
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    this->ui->lb_system_time->setText(str);
    return ;
}

void mainmenu::init_system_state() { //更新系统状态栏，同系统主窗口
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


void mainmenu::on_btn_return_clicked() { //返回系统主窗口
    emit SignFather(); //向系统主窗口发送信号，用来返回系统主窗口
}

void mainmenu::slotCheckBoxCheck(int row) { //复选框勾选操作
    /*
     * 1.生成QAbstractItemModel类对象，用来给model模型提供复选框接口
     * 2.生成QModelIndex类对象，用于定位model数据模型中帐号信息
     * 3.生成QVariant类对象，用来存储model数据模型中帐号信息
     * 4.将QVariant内存储的帐号信息和当前行数插入到单例模式的map中
    */
    QAbstractItemModel *imodel = this->ui->tableView->model();
    QModelIndex iindex = imodel->index(row, 2);
    QVariant datatemp = imodel->data(iindex);
    SingleTon::GetInstance()->insert_map_info(row, datatemp.toString());
}

void mainmenu::slotCheckBoxUncheck(int row) { //复选框取消勾选操作
    SingleTon::GetInstance()->delete_map_info(row); //根据取消勾选的行数到map中进行索引，找到后删除map中对应的帐号信息
}

bool mainmenu::eventFilter(QObject *target, QEvent *event) { //事件过滤器，目的是为了防止滚动条滚动
    if (target == this->ui->tableView->verticalScrollBar()){ //判断过滤的目标是否为tableview中的滚动条
        if(event->type() == QEvent::Wheel) { //如果是滚动条事件， 则设置为滚动条上下滚动时什么也不做
            QWheelEvent *event1 = static_cast<QWheelEvent *>(event);
            if (event1->delta() < 0) {
                //do nothing
            }
            if (event1->delta() > 0) {
                //do nothing
            }
            return true;
       }
    }
    return QMainWindow::eventFilter(target, event); //返回过滤后的滚动条事件
}

void mainmenu::checkbox_select_all() { //勾选当前页面的全部复选框，有BUG，没有想到好的处理办法
    QModelIndex index;
    int tmp_count = (currentPage - 1) * (pg.pageLine(this->ui->tableView)) + 1; //计算当前页的第一条条目编号
    int tmp_end = currentPage * pg.pageLine(this->ui->tableView) + 1;//计算当前页的最后一条条目编号
    for(int i = tmp_count - 1; i < tmp_end; i++) { //根据计算得到的编号值遍历当前页面复选框
        index = ui->tableView->model()->index(i, 0, QModelIndex());
        model->setData(index, Qt::Checked, Qt::CheckStateRole); //将遍历到的复选框设置为勾选状态
    }
    this->ui->tableView->reset(); //刷新tableview
    return ;
}

void mainmenu::checkbox_deselect_all() {//取消勾选当前页面的全部复选框，同有BUG
    QModelIndex index;
    for(int i = 0; i < this->model->rowCount(); i++) {
        index = ui->tableView->model()->index(i, 0, QModelIndex());
        model->setData(index, Qt::Unchecked, Qt::CheckStateRole);  //将遍历到的复选框设置为取消勾选状态
    }
    this->ui->tableView->reset();
    return ;
}
