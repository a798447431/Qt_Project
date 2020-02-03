/********************************************************************************
** Form generated from reading UI file 'changeinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFO_H
#define UI_CHANGEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_changeinfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_changeinfo_title;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_22;
    QLabel *lb_changeinfo_account_num;
    QLineEdit *le_changeinfo_account_num;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_23;
    QLabel *lb_changeinfo_pwd;
    QLineEdit *le_changeinfo_pwd;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_24;
    QLabel *lb_changeinfo_systemrole;
    QComboBox *cb_changeinfo_systemrole;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_25;
    QLabel *lb_changeinfo_username;
    QLineEdit *le_changeinfo_username;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_26;
    QLabel *lb_changeinfo_usersex;
    QComboBox *cb_changeinfo_usersex;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_27;
    QLabel *lb_changeinfo_organization;
    QLineEdit *le_changeinfo_organization;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_28;
    QLabel *lb_changeinfo_organization_code;
    QLineEdit *le_changeinfo_organization_code;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_29;
    QLabel *lb_changeinfo_duty;
    QLineEdit *le_changeinfo_duty;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_30;
    QLabel *lb_changeinfo_duty_code;
    QLineEdit *le_changeinfo_duty_code;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_changeinfo_confirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_changeinfo_cancle;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *changeinfo)
    {
        if (changeinfo->objectName().isEmpty())
            changeinfo->setObjectName(QString::fromUtf8("changeinfo"));
        changeinfo->resize(530, 820);
        verticalLayout = new QVBoxLayout(changeinfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lb_changeinfo_title = new QLabel(changeinfo);
        lb_changeinfo_title->setObjectName(QString::fromUtf8("lb_changeinfo_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_changeinfo_title->sizePolicy().hasHeightForWidth());
        lb_changeinfo_title->setSizePolicy(sizePolicy);
        lb_changeinfo_title->setStyleSheet(QString::fromUtf8("font: 36pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        lb_changeinfo_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_changeinfo_title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_22);

        lb_changeinfo_account_num = new QLabel(changeinfo);
        lb_changeinfo_account_num->setObjectName(QString::fromUtf8("lb_changeinfo_account_num"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lb_changeinfo_account_num->sizePolicy().hasHeightForWidth());
        lb_changeinfo_account_num->setSizePolicy(sizePolicy1);
        lb_changeinfo_account_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lb_changeinfo_account_num);

        le_changeinfo_account_num = new QLineEdit(changeinfo);
        le_changeinfo_account_num->setObjectName(QString::fromUtf8("le_changeinfo_account_num"));
        le_changeinfo_account_num->setReadOnly(true);

        horizontalLayout->addWidget(le_changeinfo_account_num);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_23);

        lb_changeinfo_pwd = new QLabel(changeinfo);
        lb_changeinfo_pwd->setObjectName(QString::fromUtf8("lb_changeinfo_pwd"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_pwd->sizePolicy().hasHeightForWidth());
        lb_changeinfo_pwd->setSizePolicy(sizePolicy1);
        lb_changeinfo_pwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lb_changeinfo_pwd);

        le_changeinfo_pwd = new QLineEdit(changeinfo);
        le_changeinfo_pwd->setObjectName(QString::fromUtf8("le_changeinfo_pwd"));

        horizontalLayout_2->addWidget(le_changeinfo_pwd);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_24);

        lb_changeinfo_systemrole = new QLabel(changeinfo);
        lb_changeinfo_systemrole->setObjectName(QString::fromUtf8("lb_changeinfo_systemrole"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_systemrole->sizePolicy().hasHeightForWidth());
        lb_changeinfo_systemrole->setSizePolicy(sizePolicy1);
        lb_changeinfo_systemrole->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_changeinfo_systemrole);

        cb_changeinfo_systemrole = new QComboBox(changeinfo);
        cb_changeinfo_systemrole->addItem(QString());
        cb_changeinfo_systemrole->addItem(QString());
        cb_changeinfo_systemrole->addItem(QString());
        cb_changeinfo_systemrole->addItem(QString());
        cb_changeinfo_systemrole->setObjectName(QString::fromUtf8("cb_changeinfo_systemrole"));

        horizontalLayout_4->addWidget(cb_changeinfo_systemrole);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_25);

        lb_changeinfo_username = new QLabel(changeinfo);
        lb_changeinfo_username->setObjectName(QString::fromUtf8("lb_changeinfo_username"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_username->sizePolicy().hasHeightForWidth());
        lb_changeinfo_username->setSizePolicy(sizePolicy1);
        lb_changeinfo_username->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lb_changeinfo_username);

        le_changeinfo_username = new QLineEdit(changeinfo);
        le_changeinfo_username->setObjectName(QString::fromUtf8("le_changeinfo_username"));

        horizontalLayout_5->addWidget(le_changeinfo_username);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_5->setStretch(1, 2);
        horizontalLayout_5->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_26);

        lb_changeinfo_usersex = new QLabel(changeinfo);
        lb_changeinfo_usersex->setObjectName(QString::fromUtf8("lb_changeinfo_usersex"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_usersex->sizePolicy().hasHeightForWidth());
        lb_changeinfo_usersex->setSizePolicy(sizePolicy1);
        lb_changeinfo_usersex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lb_changeinfo_usersex);

        cb_changeinfo_usersex = new QComboBox(changeinfo);
        cb_changeinfo_usersex->addItem(QString());
        cb_changeinfo_usersex->addItem(QString());
        cb_changeinfo_usersex->addItem(QString());
        cb_changeinfo_usersex->setObjectName(QString::fromUtf8("cb_changeinfo_usersex"));

        horizontalLayout_6->addWidget(cb_changeinfo_usersex);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_27);

        lb_changeinfo_organization = new QLabel(changeinfo);
        lb_changeinfo_organization->setObjectName(QString::fromUtf8("lb_changeinfo_organization"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_organization->sizePolicy().hasHeightForWidth());
        lb_changeinfo_organization->setSizePolicy(sizePolicy1);
        lb_changeinfo_organization->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(lb_changeinfo_organization);

        le_changeinfo_organization = new QLineEdit(changeinfo);
        le_changeinfo_organization->setObjectName(QString::fromUtf8("le_changeinfo_organization"));

        horizontalLayout_7->addWidget(le_changeinfo_organization);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        horizontalLayout_7->setStretch(1, 2);
        horizontalLayout_7->setStretch(2, 8);
        horizontalLayout_7->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_28);

        lb_changeinfo_organization_code = new QLabel(changeinfo);
        lb_changeinfo_organization_code->setObjectName(QString::fromUtf8("lb_changeinfo_organization_code"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_organization_code->sizePolicy().hasHeightForWidth());
        lb_changeinfo_organization_code->setSizePolicy(sizePolicy1);
        lb_changeinfo_organization_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(lb_changeinfo_organization_code);

        le_changeinfo_organization_code = new QLineEdit(changeinfo);
        le_changeinfo_organization_code->setObjectName(QString::fromUtf8("le_changeinfo_organization_code"));

        horizontalLayout_8->addWidget(le_changeinfo_organization_code);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        horizontalLayout_8->setStretch(1, 2);
        horizontalLayout_8->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_29);

        lb_changeinfo_duty = new QLabel(changeinfo);
        lb_changeinfo_duty->setObjectName(QString::fromUtf8("lb_changeinfo_duty"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_duty->sizePolicy().hasHeightForWidth());
        lb_changeinfo_duty->setSizePolicy(sizePolicy1);
        lb_changeinfo_duty->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(lb_changeinfo_duty);

        le_changeinfo_duty = new QLineEdit(changeinfo);
        le_changeinfo_duty->setObjectName(QString::fromUtf8("le_changeinfo_duty"));

        horizontalLayout_9->addWidget(le_changeinfo_duty);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_20);

        horizontalLayout_9->setStretch(1, 2);
        horizontalLayout_9->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_30);

        lb_changeinfo_duty_code = new QLabel(changeinfo);
        lb_changeinfo_duty_code->setObjectName(QString::fromUtf8("lb_changeinfo_duty_code"));
        sizePolicy1.setHeightForWidth(lb_changeinfo_duty_code->sizePolicy().hasHeightForWidth());
        lb_changeinfo_duty_code->setSizePolicy(sizePolicy1);
        lb_changeinfo_duty_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(lb_changeinfo_duty_code);

        le_changeinfo_duty_code = new QLineEdit(changeinfo);
        le_changeinfo_duty_code->setObjectName(QString::fromUtf8("le_changeinfo_duty_code"));

        horizontalLayout_10->addWidget(le_changeinfo_duty_code);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_21);

        horizontalLayout_10->setStretch(1, 2);
        horizontalLayout_10->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        btn_changeinfo_confirm = new QPushButton(changeinfo);
        btn_changeinfo_confirm->setObjectName(QString::fromUtf8("btn_changeinfo_confirm"));

        horizontalLayout_11->addWidget(btn_changeinfo_confirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        btn_changeinfo_cancle = new QPushButton(changeinfo);
        btn_changeinfo_cancle->setObjectName(QString::fromUtf8("btn_changeinfo_cancle"));

        horizontalLayout_11->addWidget(btn_changeinfo_cancle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 3);
        horizontalLayout_11->setStretch(2, 2);
        horizontalLayout_11->setStretch(3, 3);
        horizontalLayout_11->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout_11);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 1);
        verticalLayout->setStretch(7, 1);
        verticalLayout->setStretch(8, 1);
        verticalLayout->setStretch(9, 1);
        verticalLayout->setStretch(10, 1);
        verticalLayout->setStretch(11, 1);
        verticalLayout->setStretch(12, 1);

        retranslateUi(changeinfo);

        QMetaObject::connectSlotsByName(changeinfo);
    } // setupUi

    void retranslateUi(QDialog *changeinfo)
    {
        changeinfo->setWindowTitle(QCoreApplication::translate("changeinfo", "\347\274\226\350\276\221\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        lb_changeinfo_title->setText(QCoreApplication::translate("changeinfo", "\347\274\226\350\276\221\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        lb_changeinfo_account_num->setText(QCoreApplication::translate("changeinfo", " \345\270\220\345\217\267:", nullptr));
        le_changeinfo_account_num->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\350\276\223\345\205\245\345\270\220\345\217\267", nullptr));
        lb_changeinfo_pwd->setText(QCoreApplication::translate("changeinfo", "\344\277\256\346\224\271\345\257\206\347\240\201:", nullptr));
        le_changeinfo_pwd->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        lb_changeinfo_systemrole->setText(QCoreApplication::translate("changeinfo", "\347\263\273\347\273\237\350\247\222\350\211\262:", nullptr));
        cb_changeinfo_systemrole->setItemText(0, QString());
        cb_changeinfo_systemrole->setItemText(1, QCoreApplication::translate("changeinfo", "\346\225\231\347\273\203\345\221\230", nullptr));
        cb_changeinfo_systemrole->setItemText(2, QCoreApplication::translate("changeinfo", "\345\217\227\350\256\255\350\200\205", nullptr));
        cb_changeinfo_systemrole->setItemText(3, QCoreApplication::translate("changeinfo", "\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230", nullptr));

        lb_changeinfo_username->setText(QCoreApplication::translate("changeinfo", "\345\247\223\345\220\215:", nullptr));
        le_changeinfo_username->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\344\277\256\346\224\271\345\247\223\345\220\215", nullptr));
        lb_changeinfo_usersex->setText(QCoreApplication::translate("changeinfo", "\346\200\247\345\210\253:", nullptr));
        cb_changeinfo_usersex->setItemText(0, QString());
        cb_changeinfo_usersex->setItemText(1, QCoreApplication::translate("changeinfo", "\347\224\267", nullptr));
        cb_changeinfo_usersex->setItemText(2, QCoreApplication::translate("changeinfo", "\345\245\263", nullptr));

        lb_changeinfo_organization->setText(QCoreApplication::translate("changeinfo", "\346\234\272\346\236\204:", nullptr));
        le_changeinfo_organization->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\344\277\256\346\224\271\346\234\272\346\236\204", nullptr));
        lb_changeinfo_organization_code->setText(QCoreApplication::translate("changeinfo", "\346\234\272\346\236\204\344\273\243\347\240\201:", nullptr));
        le_changeinfo_organization_code->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\344\277\256\346\224\271\346\234\272\346\236\204\344\273\243\347\240\201", nullptr));
        lb_changeinfo_duty->setText(QCoreApplication::translate("changeinfo", "\350\201\214\345\212\241:", nullptr));
        le_changeinfo_duty->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\350\276\223\345\205\245\346\234\272\346\236\204", nullptr));
        lb_changeinfo_duty_code->setText(QCoreApplication::translate("changeinfo", "\350\201\214\345\212\241\344\273\243\347\240\201:", nullptr));
        le_changeinfo_duty_code->setPlaceholderText(QCoreApplication::translate("changeinfo", "\350\257\267\350\276\223\345\205\245\346\234\272\346\236\204\344\273\243\347\240\201", nullptr));
        btn_changeinfo_confirm->setText(QCoreApplication::translate("changeinfo", "\344\277\235\345\255\230", nullptr));
        btn_changeinfo_cancle->setText(QCoreApplication::translate("changeinfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeinfo: public Ui_changeinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFO_H
