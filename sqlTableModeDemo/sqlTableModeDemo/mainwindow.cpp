#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QVector>
#include <QSqlError>
#include <QSqlRecord>

#include "mysqltablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    setWindowTitle("sqlTableModelDemo");
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("demo.db");

    // 数据库文件是否在应用程序目录下,因为在编码时,应用程序默认路径在.pro文件夹下，但是实际exe路径在的其debug或者release文件夹下
    // 补充：不论linux还是windows，统一使用单斜杠作为分隔，在linux和windows下都能识别，能更好的跨平台
#if 1
    // 发布时
    QString path = qApp->applicationDirPath()+"/"+"demo.db";
#else
    // 编译时
    QString path = qApp->applicationDirPath()+"/../"+"demo.db";
#endif
    if(QFile::exists(path))

    {
        // 存在则打开
        _db.open();
    }else{
        // 不存在打开并创建数据库表 补充：SQLite是基于文件的数据库，当打开时如果数据库文件不存在将自动创建一个
        _db.open();
        QSqlQuery query;
        // set为sqlite关键字，不能使用
        bool bRet = query.exec("create table init(" \
                               "no   INT    PRIMARY KEY NOT NULL,"\
                               "name TEXT   NOT NULL,"\
                               "content TEXT,"\
                               "description TEXT"\
                               ");");
        if(!bRet) {
            _db.close();
            QFile::remove(path);
        }else{
            // 此处演示了三种不同insert插入方法
            query.exec("insert into init values" \
                       "(1, '启动界面背景', 'images/background.jpg', '请使用1920*1080的图片，图片格式可以为png、jpg。');");
            query.exec("insert into init       " \
                       "(no,name,content,description) values(2, '欢迎视频', '','进入启动界面后，循环播放的视频,必须为mp4格式，如果为空则循环播放欢迎音乐');");
            query.exec("insert into init       " \
                       "(no,name,description) values (3, '欢迎音乐','进去启动界面后，循环播放的音频文件，可选择mp3,wav格式');");
        }
    }
    // 如果使用MySqlTableModel，重写了data，但是导致直接点击数据修改的时候，没有更新TableView，不知原因
    // 如果使用QSqlTableMode，则无法通过重载实现每一行自动居中等一些单元格的统一操作，只能遍历单元格设置
    QSqlTableModel *pModel = new QSqlTableModel(this, _db);
    pModel->setTable("init");
    // 三种提交方式，改动即提交，选择其他行时提交，手动提交；经实际测试，其中只有手动提交在显示效果上是最好的
    pModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    pModel->select();
    pModel->setHeaderData(0, Qt::Horizontal, "序号");
    pModel->setHeaderData(1, Qt::Horizontal, "名称");
    pModel->setHeaderData(2, Qt::Horizontal, "内容");
    pModel->setHeaderData(3, Qt::Horizontal, "描述");
    pModel->sort(0, Qt::AscendingOrder); // 第0列降序排序
    ui->tableView->setModel(pModel);
   // grid原本就是有多少格显示多少格，
//    ui->tableView->setShowGrid(false); // 可隐藏grid
      // 只能单选
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
     // 以行作为选择标准
    ui->tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);
    // 行头隐藏
    ui->tableView->verticalHeader()->hide();
    // 让列头可被点击，触发点击事件
    ui->tableView->horizontalHeader()->setSectionsClickable(true);
    // 去掉选中表格时，列头的文字高亮
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);
    // 列头灰色
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sortByColumn(int col)
{
    QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    bool ascending = (ui->tableView->horizontalHeader()->sortIndicatorSection()==col
                      && ui->tableView->horizontalHeader()->sortIndicatorOrder()==Qt::DescendingOrder);
    Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
    pMode->sort(col, order);
}

void MainWindow::on_pushButton_save_clicked()
{

    QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    pMode->database().transaction(); //开始事务操作
    if (pMode->submitAll()) // 提交所有被修改的数据到数据库中
    {
        pMode->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        pMode->database().rollback(); //提交失败，事务回滚
        QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(pMode->lastError().text()));
    }
    pMode->revertAll(); //撤销修改
}

void MainWindow::on_pushButton_add_clicked()
{
    QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
//    pMode->insertRow(pMode->rowCount());
    QSqlRecord record = pMode->record();
    int number;
    // 从1开始遍历，遇到相同的，自增再遍历，直到没有相同的作为number插入
    // 防止唯一主键重复导致提交失败，因为提交失败tableview还是会更新修改后的（视图）
    for(number = 1; ; number++)
    {
        bool bFlag = false;
        for(int index = 0; index < pMode->rowCount(); index++) {
            if(pMode->index(index, 0).data().toInt() == number) {
                bFlag = true;
                break;
            }
        }
        if(!bFlag) {
            break;
        }
    }
    //
    record.setValue(0, number);
    record.setValue(1, "未命令");
    record.setValue(2, "空");
    record.setValue(3, "空");
    pMode->insertRecord(pMode->rowCount(), record);
    // 每次手动提交，都会重新刷新tableView，保持mode和tableView一致
    pMode->submitAll();
}

void MainWindow::on_pushButton_del_clicked()
{
    QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    // 当QSqlTableModel::EditStrategy 选择 非QSqlTableModel::OnManualSubmit 时,
    // 每次删除都可删除掉model，但是tableview那一列为空，一直在，只好设置为 QSqlTableModel::OnManualSubmit
    pMode->removeRow(ui->tableView->currentIndex().row());
    // 每次手动提交，都会重新刷新tableView，保持mode和tableView一致
    pMode->submitAll();
}

