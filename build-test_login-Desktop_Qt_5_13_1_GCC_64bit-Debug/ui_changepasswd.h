/********************************************************************************
** Form generated from reading UI file 'changepasswd.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWD_H
#define UI_CHANGEPASSWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_changepasswd
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_title;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *le_changepwd_newpwd;
    QLineEdit *le_changepwd_oldpwd;
    QLineEdit *le_changepwd_repwd;
    QLabel *lb_changepwd_repwd;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_13;
    QLabel *lb_changepwd_oldpwd;
    QLabel *lb_changepwd_newpwd;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_changepwd;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_changepwd_exit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *changepasswd)
    {
        if (changepasswd->objectName().isEmpty())
            changepasswd->setObjectName(QString::fromUtf8("changepasswd"));
        changepasswd->resize(530, 410);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(changepasswd->sizePolicy().hasHeightForWidth());
        changepasswd->setSizePolicy(sizePolicy);
        changepasswd->setMinimumSize(QSize(530, 410));
        changepasswd->setMaximumSize(QSize(530, 410));
        verticalLayout = new QVBoxLayout(changepasswd);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_title = new QLabel(changepasswd);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy1);
        label_title->setStyleSheet(QString::fromUtf8("font: 26pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";"));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        le_changepwd_newpwd = new QLineEdit(changepasswd);
        le_changepwd_newpwd->setObjectName(QString::fromUtf8("le_changepwd_newpwd"));
        le_changepwd_newpwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(le_changepwd_newpwd, 1, 2, 1, 1);

        le_changepwd_oldpwd = new QLineEdit(changepasswd);
        le_changepwd_oldpwd->setObjectName(QString::fromUtf8("le_changepwd_oldpwd"));
        le_changepwd_oldpwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_changepwd_oldpwd, 0, 2, 1, 1);

        le_changepwd_repwd = new QLineEdit(changepasswd);
        le_changepwd_repwd->setObjectName(QString::fromUtf8("le_changepwd_repwd"));
        le_changepwd_repwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(le_changepwd_repwd, 2, 2, 1, 1);

        lb_changepwd_repwd = new QLabel(changepasswd);
        lb_changepwd_repwd->setObjectName(QString::fromUtf8("lb_changepwd_repwd"));
        lb_changepwd_repwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_changepwd_repwd, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 2, 0, 1, 1);

        lb_changepwd_oldpwd = new QLabel(changepasswd);
        lb_changepwd_oldpwd->setObjectName(QString::fromUtf8("lb_changepwd_oldpwd"));
        lb_changepwd_oldpwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_changepwd_oldpwd, 0, 1, 1, 1);

        lb_changepwd_newpwd = new QLabel(changepasswd);
        lb_changepwd_newpwd->setObjectName(QString::fromUtf8("lb_changepwd_newpwd"));
        lb_changepwd_newpwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_changepwd_newpwd, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 7);
        gridLayout->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_changepwd = new QPushButton(changepasswd);
        btn_changepwd->setObjectName(QString::fromUtf8("btn_changepwd"));

        horizontalLayout->addWidget(btn_changepwd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_changepwd_exit = new QPushButton(changepasswd);
        btn_changepwd_exit->setObjectName(QString::fromUtf8("btn_changepwd_exit"));

        horizontalLayout->addWidget(btn_changepwd_exit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(3, 8);
        verticalLayout->setStretch(5, 1);

        retranslateUi(changepasswd);

        QMetaObject::connectSlotsByName(changepasswd);
    } // setupUi

    void retranslateUi(QDialog *changepasswd)
    {
        changepasswd->setWindowTitle(QCoreApplication::translate("changepasswd", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_title->setText(QCoreApplication::translate("changepasswd", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        le_changepwd_newpwd->setPlaceholderText(QCoreApplication::translate("changepasswd", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        le_changepwd_oldpwd->setPlaceholderText(QCoreApplication::translate("changepasswd", "\350\257\267\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201", nullptr));
        le_changepwd_repwd->setPlaceholderText(QCoreApplication::translate("changepasswd", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        lb_changepwd_repwd->setText(QCoreApplication::translate("changepasswd", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201:", nullptr));
        lb_changepwd_oldpwd->setText(QCoreApplication::translate("changepasswd", "\346\227\247\345\257\206\347\240\201:", nullptr));
        lb_changepwd_newpwd->setText(QCoreApplication::translate("changepasswd", "\346\226\260\345\257\206\347\240\201:", nullptr));
        btn_changepwd->setText(QCoreApplication::translate("changepasswd", "\344\277\256\346\224\271", nullptr));
        btn_changepwd_exit->setText(QCoreApplication::translate("changepasswd", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changepasswd: public Ui_changepasswd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWD_H
