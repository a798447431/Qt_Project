/********************************************************************************
** Form generated from reading UI file 'myform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QGridLayout *gridLayout_2;
    QLabel *namelabel;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *ageEdit;
    QPushButton *okBtn;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPlainTextEdit *jsEdit;
    QPushButton *callJsBtn;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(716, 420);
        gridLayout_2 = new QGridLayout(MyForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        namelabel = new QLabel(MyForm);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));

        gridLayout_2->addWidget(namelabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(MyForm);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout_2->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        ageEdit = new QLineEdit(MyForm);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));

        gridLayout_2->addWidget(ageEdit, 1, 1, 1, 1);

        okBtn = new QPushButton(MyForm);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout_2->addWidget(okBtn, 2, 0, 1, 2);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 2);

        widget = new QWidget(MyForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        jsEdit = new QPlainTextEdit(widget);
        jsEdit->setObjectName(QString::fromUtf8("jsEdit"));
        jsEdit->setGeometry(QRect(60, 20, 201, 111));
        callJsBtn = new QPushButton(widget);
        callJsBtn->setObjectName(QString::fromUtf8("callJsBtn"));
        callJsBtn->setGeometry(QRect(100, 140, 93, 28));

        gridLayout_2->addWidget(widget, 3, 2, 1, 1);


        retranslateUi(MyForm);

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QCoreApplication::translate("MyForm", "Form", nullptr));
        namelabel->setText(QCoreApplication::translate("MyForm", "name", nullptr));
        label_2->setText(QCoreApplication::translate("MyForm", "age", nullptr));
        okBtn->setText(QCoreApplication::translate("MyForm", "ok", nullptr));
        pushButton->setText(QCoreApplication::translate("MyForm", "js alert", nullptr));
        callJsBtn->setText(QCoreApplication::translate("MyForm", "callJsBtn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
