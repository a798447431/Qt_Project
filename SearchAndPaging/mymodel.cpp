
#include "mymodel.h"
#include <QMap>
#include <QDebug>


MyModel::MyModel(QObject *parent)
    : QSqlQueryModel(parent)
{


}


Qt::ItemFlags MyModel::flags(const QModelIndex &index) const {

    Qt::ItemFlags flags = QSqlQueryModel::flags(index);

    if (index.column() == 0)
     return  flags|= Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
        //flags |= Qt::ItemIsUserCheckable;



    return flags;

}

QVariant MyModel::data(const QModelIndex &index,  int role) const {


    if (!index.isValid())
    return QVariant();

    if (index.column() != 0 )
    {
      return QSqlQueryModel::data(index, role);
    }

  QVariant value = QSqlQueryModel::data(index, role);

  if (role == Qt::CheckStateRole && index.column() == 0)

  {

    return check_state_map[index.data(Qt::DisplayRole)] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
  }
           // return (QSqlQueryModel::data(index).toInt() == 0) ?  Qt::Unchecked:Qt::Checked;

  else

    return value;

}


bool MyModel::setData( const QModelIndex & index, const QVariant & value, int role)
{
    if(!index.isValid())
      return false;

    //if(index.isValid() && role == Qt::CheckStateRole&&index.column()==0)
    if( role == Qt::CheckStateRole&&index.column()==0)
    {
        if(value.value<int>()==Qt::Checked)
        {
            //m_config->setAutoRun(index.row(), true);
            check_state_map[index.data(Qt::DisplayRole)] = (value == Qt::Checked ? Qt::Checked : Qt::Unchecked);
            return true;
           // check_state_map[index.row()] =Qt::Unchecked;
            //return QSqlQueryModel::setData(index, Qt::Checked,role);
        }
        else
        {
          //  return QSqlQueryModel::setData(index,value,role);
             check_state_map[index.data(Qt::DisplayRole)] = (value == Qt::Checked ? Qt::Checked : Qt::Unchecked);

            //index.model()->setData(index,0,Qt::EditRole);
           // m_config->setAutoRun(index.row(), false);
        }
        emit dataChanged(index, index);
       // return true;
    }
    return false;
}

void MyModel::getCheckBoxChanged(bool isOn)
{
    //qDebug()<<"come in getCheckBoxChanged()";
   // qDebug()<<isOn;
    QMap<QVariant, Qt::CheckState>::const_iterator i;
    if(isOn)
    {

        for (i = check_state_map.constBegin(); i != check_state_map.constEnd(); ++i) {
           // qDebug() << i.key() << ":" << i.value();
            check_state_map[i.key()]=Qt::Checked;
        }
    }
    else
    {

        for (i = check_state_map.constBegin(); i != check_state_map.constEnd(); ++i) {
           // qDebug() << i.key() << ":" << i.value();
            check_state_map[i.key()]=Qt::Unchecked;
        }
    }
    //rowResized()
    //emit dataChanged();
      //  emit resetInternalData();
      QModelIndex it;
     this->dataChanged(it,it);

}
