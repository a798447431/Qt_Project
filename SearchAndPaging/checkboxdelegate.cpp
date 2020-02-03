#include "checkboxdelegate.h"

#include <QCheckBox>


CheckBoxDelegate::CheckBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
      QCheckBox *box=new QCheckBox;
      box->setChecked(false);

      return box;
}

void CheckBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
  //  int value = index.model()->data(index, Qt::EditRole).toInt();

   // QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    //spinBox->setValue(value);
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QCheckBox *Box = static_cast<QCheckBox*>(editor);
   // Box->interpretText();


   // model->setData(index, value, Qt::EditRole);
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
