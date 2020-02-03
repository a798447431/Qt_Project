#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <headerview.h>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <mymodel.h>
#include <QtSql>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    HeaderView *myHeader;

private slots:
      void OnPrevButtonClick();
      void OnNextButtonClick();
      void OnSearchButtonClick();
      void OnShowAllButtonClick();

signals:
      void queryChange();

private:
    Ui::MainWindow *ui;

    void showError(const QSqlError &err);
    void ninitTableHeader();
    void SetTableView(QMap<QString,QString> *params=0);//设置表格
    int  GetTotalRecordCount(QMap<QString,QString> *params=0);//得到记录数
    int  GetPageCount();//得到页数
    void RecordQuery(int limitIndex,QMap<QString,QString> *params=0);//记录查询
    void UpdateStatus();//刷新状态
    void SetTotalPageLabel(); //设置总数页文本
    QString GetQueryString(QMap<QString,QString> *params);//得到查询字符串
    MyModel *queryModel;//查询模型

   // HeaderView *myHeader;
    int       currentPage;      //当前页
    int       totalPage;    //总页数
    int       totalRecrodCount;     //总记录数
    enum      {PageRecordCount = 5};//每页显示记录数
    QMap<QString,QString> *params=NULL;
};

#endif // MAINWINDOW_H
