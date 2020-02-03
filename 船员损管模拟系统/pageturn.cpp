#include "pageturn.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

 /*
  * QTableView：：verticalScrollBar()->setSliderPosition()；设置当前滑动条的位置
  * QTableView：：verticalScrollBar()->maximum(); 滑动条能移动的最大位置
  * QTableView：：verticalScrollBar()->value(); 获得当前滑动条的位置
 */
pageturn::pageturn()
{

}

int pageturn::pageCount(QTableView *p) //QTableView 总页数
{
    if(p == NULL)  return -1;
    int rowCount = p->model()->rowCount();
    int rowHeight = p->rowHeight(0);
    int tableViewHeight = p->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1; //每页显示行数
    int ret = rowCount / rowCountPerPage;
    int tem = rowCount % rowCountPerPage;
    if (tem != 0) ret++;
    return ret;
}

int pageturn::pageLine(QTableView *p) {
    if(p == NULL)  return -1;
    int rowHeight = p->rowHeight(0);
    int tableViewHeight = p->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1;
    return rowCountPerPage;
}

bool pageturn::pageTo(QTableView *p, int pageNO)//翻到指定页
{
    if (p == NULL)  return false;
    int maxPage = pageCount(p);
    if(pageNO > maxPage)  return false;
    int rowCount = p->model()->rowCount();
    int rowHeight = p->rowHeight(0);
    int tableViewHeight = p->height();
    int rowCountPerPage = tableViewHeight / rowHeight-1; //每页显示行数
    int canNotViewCount = rowCount - rowCountPerPage; //看不见的行数
    if (canNotViewCount == 0) return false;
    int maxValue = p->verticalScrollBar()->maximum(); //当前SCROLLER最大显示值
    if(maxValue == 0) return false;
    int pageValue = (maxValue * rowCountPerPage) / canNotViewCount;
    p->verticalScrollBar()->setSliderPosition(pageValue * (pageNO - 1));
    return true;
}


bool pageturn::pageUp(QTableView *p)//上翻
{
    if(p == NULL)  return false;
    int rowCount = p->model()->rowCount();
    int rowHeight = p->rowHeight(0);
    int tableViewHeight = p->height();
    int rowCountPerPage = tableViewHeight/rowHeight-1; //每页显示行数
    int canNotViewCount = rowCount-rowCountPerPage;	//看不见的行数
    if (canNotViewCount == 0) return false;
    int maxValue = p->verticalScrollBar()->maximum(); //当前SCROLLER最大显示值
    if (maxValue == 0) return false;
    int pageValue = (maxValue*rowCountPerPage) / canNotViewCount;
    int nCurScroller = p->verticalScrollBar()->value();	//获得当前scroller值
    if(nCurScroller > 0) p->verticalScrollBar()->setSliderPosition(nCurScroller-pageValue);
    return true;
}

bool pageturn::pageDown(QTableView *p) //下翻
{
    if (p == NULL)  return false;
    int rowCount = p->model()->rowCount();
    int rowHeight = p->rowHeight(0);
    int tableViewHeight = p->height();
    int rowCountPerPage = tableViewHeight / rowHeight - 1; //每页显示行数
    int canNotViewCount = rowCount-rowCountPerPage;	//看不见的行数
    if (canNotViewCount == 0) return false;
    int maxValue = p->verticalScrollBar()->maximum(); //当前SCROLLER最大显示值

    if (maxValue == 0) return false;
    int pageValue = (maxValue * rowCountPerPage) / canNotViewCount;
    int nCurScroller = p->verticalScrollBar()->value();	 //获得当前scroller值
    if(nCurScroller<maxValue) p->verticalScrollBar()->setSliderPosition(nCurScroller+pageValue);
    return true;
}

bool pageturn::pageHome(QTableView *p) //首页
{
    if(p == NULL) return false;
    int maxValue = p->verticalScrollBar()->maximum(); //当前SCROLLER最大显示值
    if(maxValue == 0) return false;
    p->verticalScrollBar()->setSliderPosition(0);
    return true;
}

bool pageturn::pageEnd(QTableView *p)//末页
{
    if(p == NULL) return false;
    int maxValue = p->verticalScrollBar()->maximum(); //当前SCROLLER最大显示值
    if(maxValue == 0)  return false;
    p->verticalScrollBar()->setSliderPosition(maxValue);
    return true;
}

