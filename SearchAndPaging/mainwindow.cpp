#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QRegExp>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "QMessageBox"
#include <map>
#include <QtSql>
#include "mymodel.h"
#include "checkboxdelegate.h"
#include <QDebug>
#include "headerview.h"
#include "initdb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("分页查询示例");
    ui->setupUi(this);



    if (!QSqlDatabase::drivers().contains("QMYSQL"))
        QMessageBox::critical(this, "Unable to load database", "This demo needs the MYSQL driver");

    // initialize the database
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }







//    QSqlDatabase db;
//    if(QSqlDatabase::contains("qt_sql_default_connection"))
//      db = QSqlDatabase::database("qt_sql_default_connection");
//    else
//      db = QSqlDatabase::addDatabase("QMYSQL");

//       db.setHostName("localhost");
//       db.setDatabaseName("test");
//       db.setUserName("root");
//       db.setPassword("123456");

//       bool ok = db.open();

//       if(ok)
//       {

//           // QMessageBox::warning(this,tr("提示"),tr("打开数据库成功"),QMessageBox::Ok);
//       }
//       else
//       {
//            QMessageBox::warning(this,tr("提示"),tr("打开数据库失败"),QMessageBox::Ok);
//       }
        myHeader = new HeaderView(Qt::Horizontal, ui->tableView);
        ui->tableView->setHorizontalHeader(myHeader);
    SetTableView();
    connect(ui->prevButton,SIGNAL(clicked()),this,SLOT(OnPrevButtonClick()));
    connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(OnNextButtonClick()));
      connect(ui->btn_search,SIGNAL(clicked()),this,SLOT(OnSearchButtonClick()));
     connect(ui->btn_showAll,SIGNAL(clicked()),this,SLOT(OnShowAllButtonClick()));
     connect(this,SIGNAL(queryChange()),myHeader,SLOT(receiveQueryChange()));
     //emit queryChange();

}


void MainWindow::SetTableView(QMap<QString,QString> *params)
{
if(queryModel!=NULL)
    delete queryModel;
//queryModel = new QSqlQueryModel(this);
queryModel = new MyModel(this);


//queryModel = new QSqlRelationalTableModel(this);
//设置当前页
currentPage=1;
//得到总记录数
  totalRecrodCount=GetTotalRecordCount(params);


//得到总页数
   totalPage = GetPageCount();

//刷新状态
UpdateStatus();
//设置总页数文本
SetTotalPageLabel();
//记录查询
 RecordQuery(0,params);


ui->tableView->setModel(queryModel);

connect(ui->tableView->horizontalHeader(),SIGNAL(checkBoxStateChange(bool)),queryModel,SLOT(getCheckBoxChanged(bool)));


//queryModel->removeColumn(0);
//queryModel->insertColumns(0,1);
ui->tableView->verticalHeader()->hide();
ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
ui->tableView->setStyleSheet("selection-background-color:lightblue;");
//queryModel->setHeaderData(0,Qt::Horizontal,"");
queryModel->setHeaderData(0,Qt::Horizontal,"id");
queryModel->setHeaderData(1,Qt::Horizontal,"姓名");
queryModel->setHeaderData(2,Qt::Horizontal,"门诊号");
queryModel->setHeaderData(3,Qt::Horizontal,"部位");
queryModel->setHeaderData(4,Qt::Horizontal,"性别");
queryModel->setHeaderData(5,Qt::Horizontal,"年龄");

queryModel->setHeaderData(6,Qt::Horizontal,"住院号");
queryModel->setHeaderData(7,Qt::Horizontal,"临床诊断");
queryModel->setHeaderData(8,Qt::Horizontal,"科别");
queryModel->setHeaderData(9,Qt::Horizontal,"床号");
queryModel->setHeaderData(10,Qt::Horizontal,"送诊医师");
queryModel->setHeaderData(11,Qt::Horizontal,"时间");
//queryModel->setHeaderData(12,Qt::Horizontal,"时间");
//ui->tableView->setColumnWidth(0,20);
//ui->tableView->setColumnWidth(11,150);

}


void MainWindow::ninitTableHeader()
{
    queryModel->insertColumns(0,1);
}



//得到总的记录数
int MainWindow::GetTotalRecordCount(QMap<QString,QString> *params)
{
  if(params==NULL)
    queryModel->setQuery("select * from test1");
  else
    {
      QString s=this->GetQueryString(params);
       queryModel->setQuery(s);
       if(queryModel->lastError().isValid())
       {

                 qDebug() << queryModel->lastError();
       }

    }

  int count=queryModel->rowCount();

  for(int i = 0; i < queryModel->rowCount(); i++)
    {

      // qDebug()<<queryModel->record(i).value("id").toInt();
       queryModel->check_state_map[queryModel->record(i).value("id").toInt()]=Qt::Unchecked;
    }


  return count;
}


//计算总页数
int MainWindow::GetPageCount()
{
    return (totalRecrodCount % PageRecordCount == 0) ? (totalRecrodCount / PageRecordCount) : (totalRecrodCount / PageRecordCount + 1);
}


//记录查询
void MainWindow::RecordQuery(int limitIndex,QMap<QString,QString> *params)
{
    QString szQuery,tempQuery;
    QSqlQueryModel *tempQueryModel = new QSqlQueryModel();
    static QMap<QString,QString> *tempParams=NULL;
     if(params==NULL)
     {
        szQuery = QString("select * from test1 limit %1,%2").arg(QString::number(limitIndex)).arg(QString::number(PageRecordCount));

     }else
     {


         szQuery =this->GetQueryString(params);
         szQuery.append(" limit ");
         szQuery.append(QString::number(limitIndex));
         szQuery.append(",");
         szQuery.append(QString::number(PageRecordCount));



         if(limitIndex==0 && tempParams!=params)
         {
             tempParams=params;
             tempQuery=this->GetQueryString(params);
             tempQueryModel->setQuery(tempQuery);
             //if(queryModel->check_state_map.size()>0)
                  queryModel->check_state_map.clear();

             for(int i = 0; i < tempQueryModel->rowCount(); i++)
               {

                  qDebug()<<tempQueryModel->record(i).value("id").toInt();
                  queryModel->check_state_map[tempQueryModel->record(i).value("id").toInt()]=Qt::Unchecked;
               }
         }
          delete tempQueryModel;


     }

     queryModel->setQuery(szQuery);











}


void MainWindow::UpdateStatus()
{
    QString szCurrentText=QString("当前第%1页").arg(QString::number(currentPage));
    ui->currentPageLabel->setText(szCurrentText);
  //设置按钮是否可用
  if(currentPage==1)
   {
      ui->prevButton->setEnabled(false);
      if(totalPage==1)
        ui->nextButton->setEnabled(false);
      else
           ui->nextButton->setEnabled(true);
   }
  else if(currentPage==totalPage)
  {
      if(totalPage==1)
        ui->prevButton->setEnabled(false);
      else
          ui->prevButton->setEnabled(true);
      ui->nextButton->setEnabled(false);
  }
  else
  {
      ui->prevButton->setEnabled(true);
      ui->nextButton->setEnabled(true);
  }

}


//设置总页数
void MainWindow::SetTotalPageLabel()
{
  QString szPageCountText = QString("总共%1页").arg(QString::number(totalPage));
  ui->totalPageLabel->setText(szPageCountText);
}

//点击按钮 前一页
void MainWindow::OnPrevButtonClick()
{
  int limitIndex = (currentPage - 2) * PageRecordCount;
  RecordQuery(limitIndex,params);

  currentPage -= 1;
  UpdateStatus();
}


//点击后一页
void MainWindow::OnNextButtonClick()
{
  int limitIndex = currentPage * PageRecordCount;
  RecordQuery(limitIndex,params);

  currentPage += 1;
  UpdateStatus();
}


//点击搜索按钮
void MainWindow::OnSearchButtonClick()
{

    emit queryChange();

    QMap<QString,QString> *params=new QMap<QString,QString>;
    if(ui->line_admissionName->text()!=NULL&&ui->line_admissionName->text()!="")
      params->insert(QString("admissionNum"),ui->line_admissionName->text());
    if(ui->line_name->text()!=NULL&& ui->line_name->text()!="")
      params->insert(QString("name"),ui->line_name->text());

    if(ui->line_outpatientNum->text()!=NULL&&ui->line_outpatientNum->text()!="")
      params->insert(QString("outpatientNum"),ui->line_outpatientNum->text());
    if(ui->box_sex->currentText()!=NULL && ui->box_sex->currentText()!="")
      params->insert(QString("sex"),ui->box_sex->currentText());
    QString time=" starttime between ";
    time.append("'");
    time.append(ui->edit_starttime->text());
    time.append("' and '");
    time.append(ui->edit_endtime->text());
    time.append("'");
    params->insert(QString("starttime"),time);

    if(this->params!=NULL)
        delete this->params;
    this->params=params;
    SetTableView(this->params);

}




QString MainWindow::GetQueryString(QMap<QString,QString> *params)
{

     QString  szQuery = QString("select * from test1 where ");
    QMap<QString,QString>::iterator iter;

    QString temp;

    for(iter = params->begin(); iter != params->end(); iter++)
    {
       if(iter.key().compare(QString("starttime"))!=0)
        {
           szQuery.append(iter.key());
           szQuery.append("='");
           szQuery.append(iter.value());
           szQuery.append("' ");

               szQuery.append(" and ");


        }

       else if(iter.key().compare(QString("starttime"))==0){

           temp.append(iter.value());

       }


    }
    szQuery.append(temp);

    return szQuery;
}

void MainWindow::OnShowAllButtonClick()
{

    emit queryChange();
    this->params=NULL;
    SetTableView();

}


void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}


MainWindow::~MainWindow()
{
    delete ui;
    delete myHeader;
    delete queryModel;
}
