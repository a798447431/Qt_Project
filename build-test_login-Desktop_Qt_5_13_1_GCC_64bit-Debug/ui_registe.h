/********************************************************************************
** Form generated from reading UI file 'registe.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTE_H
#define UI_REGISTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registe
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QLabel *user_name;
    QLineEdit *le_usernum;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QLabel *pwd;
    QLineEdit *le_pwd;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *sure_pwd;
    QLineEdit *le_surepwd;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lb_system_role;
    QComboBox *cbb_system_role;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_18;
    QLabel *lb_username;
    QLineEdit *le_username;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_19;
    QLabel *lb_usersex;
    QComboBox *cbb_usersex;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_20;
    QLabel *lb_organization;
    QLineEdit *le_organization;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_21;
    QLabel *lb_origanization_code;
    QLineEdit *le_origanization_code;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_22;
    QLabel *lb_duty;
    QLineEdit *le_duty;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_23;
    QLabel *lb_duty_code;
    QLineEdit *le_duty_code;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btn_registe;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *btn_register_exit;
    QSpacerItem *horizontalSpacer_12;

    void setupUi(QDialog *registe)
    {
        if (registe->objectName().isEmpty())
            registe->setObjectName(QString::fromUtf8("registe"));
        registe->resize(530, 820);
        verticalLayout = new QVBoxLayout(registe);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        title = new QLabel(registe);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setStyleSheet(QString::fromUtf8("font: 57 26pt \"\346\226\207\346\263\211\351\251\277\347\202\271\351\230\265\346\255\243\351\273\221\";"));
        title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        user_name = new QLabel(registe);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(user_name->sizePolicy().hasHeightForWidth());
        user_name->setSizePolicy(sizePolicy1);
        user_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(user_name, 0, 1, 1, 1);

        le_usernum = new QLineEdit(registe);
        le_usernum->setObjectName(QString::fromUtf8("le_usernum"));
        sizePolicy.setHeightForWidth(le_usernum->sizePolicy().hasHeightForWidth());
        le_usernum->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_usernum, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        pwd = new QLabel(registe);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        sizePolicy1.setHeightForWidth(pwd->sizePolicy().hasHeightForWidth());
        pwd->setSizePolicy(sizePolicy1);
        pwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pwd, 1, 1, 1, 1);

        le_pwd = new QLineEdit(registe);
        le_pwd->setObjectName(QString::fromUtf8("le_pwd"));
        sizePolicy.setHeightForWidth(le_pwd->sizePolicy().hasHeightForWidth());
        le_pwd->setSizePolicy(sizePolicy);
        le_pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_pwd, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 0, 1, 1);

        sure_pwd = new QLabel(registe);
        sure_pwd->setObjectName(QString::fromUtf8("sure_pwd"));
        sizePolicy1.setHeightForWidth(sure_pwd->sizePolicy().hasHeightForWidth());
        sure_pwd->setSizePolicy(sizePolicy1);
        sure_pwd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(sure_pwd, 2, 1, 1, 1);

        le_surepwd = new QLineEdit(registe);
        le_surepwd->setObjectName(QString::fromUtf8("le_surepwd"));
        sizePolicy.setHeightForWidth(le_surepwd->sizePolicy().hasHeightForWidth());
        le_surepwd->setSizePolicy(sizePolicy);
        le_surepwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_surepwd, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 0, 1, 1);

        lb_system_role = new QLabel(registe);
        lb_system_role->setObjectName(QString::fromUtf8("lb_system_role"));
        sizePolicy1.setHeightForWidth(lb_system_role->sizePolicy().hasHeightForWidth());
        lb_system_role->setSizePolicy(sizePolicy1);
        lb_system_role->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_system_role, 3, 1, 1, 1);

        cbb_system_role = new QComboBox(registe);
        cbb_system_role->addItem(QString());
        cbb_system_role->addItem(QString());
        cbb_system_role->addItem(QString());
        cbb_system_role->addItem(QString());
        cbb_system_role->setObjectName(QString::fromUtf8("cbb_system_role"));
        sizePolicy.setHeightForWidth(cbb_system_role->sizePolicy().hasHeightForWidth());
        cbb_system_role->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cbb_system_role, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(14, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 3, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 4, 0, 1, 1);

        lb_username = new QLabel(registe);
        lb_username->setObjectName(QString::fromUtf8("lb_username"));
        sizePolicy1.setHeightForWidth(lb_username->sizePolicy().hasHeightForWidth());
        lb_username->setSizePolicy(sizePolicy1);
        lb_username->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_username, 4, 1, 1, 1);

        le_username = new QLineEdit(registe);
        le_username->setObjectName(QString::fromUtf8("le_username"));
        sizePolicy.setHeightForWidth(le_username->sizePolicy().hasHeightForWidth());
        le_username->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_username, 4, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 3, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_19, 5, 0, 1, 1);

        lb_usersex = new QLabel(registe);
        lb_usersex->setObjectName(QString::fromUtf8("lb_usersex"));
        sizePolicy1.setHeightForWidth(lb_usersex->sizePolicy().hasHeightForWidth());
        lb_usersex->setSizePolicy(sizePolicy1);
        lb_usersex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_usersex, 5, 1, 1, 1);

        cbb_usersex = new QComboBox(registe);
        cbb_usersex->addItem(QString());
        cbb_usersex->addItem(QString());
        cbb_usersex->addItem(QString());
        cbb_usersex->setObjectName(QString::fromUtf8("cbb_usersex"));
        sizePolicy.setHeightForWidth(cbb_usersex->sizePolicy().hasHeightForWidth());
        cbb_usersex->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cbb_usersex, 5, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(13, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 3, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_20, 6, 0, 1, 1);

        lb_organization = new QLabel(registe);
        lb_organization->setObjectName(QString::fromUtf8("lb_organization"));
        sizePolicy1.setHeightForWidth(lb_organization->sizePolicy().hasHeightForWidth());
        lb_organization->setSizePolicy(sizePolicy1);
        lb_organization->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_organization, 6, 1, 1, 1);

        le_organization = new QLineEdit(registe);
        le_organization->setObjectName(QString::fromUtf8("le_organization"));
        sizePolicy.setHeightForWidth(le_organization->sizePolicy().hasHeightForWidth());
        le_organization->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_organization, 6, 2, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 6, 3, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_21, 7, 0, 1, 1);

        lb_origanization_code = new QLabel(registe);
        lb_origanization_code->setObjectName(QString::fromUtf8("lb_origanization_code"));
        sizePolicy1.setHeightForWidth(lb_origanization_code->sizePolicy().hasHeightForWidth());
        lb_origanization_code->setSizePolicy(sizePolicy1);
        lb_origanization_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_origanization_code, 7, 1, 1, 1);

        le_origanization_code = new QLineEdit(registe);
        le_origanization_code->setObjectName(QString::fromUtf8("le_origanization_code"));
        sizePolicy.setHeightForWidth(le_origanization_code->sizePolicy().hasHeightForWidth());
        le_origanization_code->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_origanization_code, 7, 2, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 7, 3, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_22, 8, 0, 1, 1);

        lb_duty = new QLabel(registe);
        lb_duty->setObjectName(QString::fromUtf8("lb_duty"));
        sizePolicy1.setHeightForWidth(lb_duty->sizePolicy().hasHeightForWidth());
        lb_duty->setSizePolicy(sizePolicy1);
        lb_duty->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_duty, 8, 1, 1, 1);

        le_duty = new QLineEdit(registe);
        le_duty->setObjectName(QString::fromUtf8("le_duty"));
        sizePolicy.setHeightForWidth(le_duty->sizePolicy().hasHeightForWidth());
        le_duty->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_duty, 8, 2, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 8, 3, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_23, 9, 0, 1, 1);

        lb_duty_code = new QLabel(registe);
        lb_duty_code->setObjectName(QString::fromUtf8("lb_duty_code"));
        sizePolicy1.setHeightForWidth(lb_duty_code->sizePolicy().hasHeightForWidth());
        lb_duty_code->setSizePolicy(sizePolicy1);
        lb_duty_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lb_duty_code, 9, 1, 1, 1);

        le_duty_code = new QLineEdit(registe);
        le_duty_code->setObjectName(QString::fromUtf8("le_duty_code"));
        sizePolicy.setHeightForWidth(le_duty_code->sizePolicy().hasHeightForWidth());
        le_duty_code->setSizePolicy(sizePolicy);

        gridLayout->addWidget(le_duty_code, 9, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(18, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 9, 3, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 7);
        gridLayout->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        btn_registe = new QPushButton(registe);
        btn_registe->setObjectName(QString::fromUtf8("btn_registe"));

        horizontalLayout_11->addWidget(btn_registe);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);

        btn_register_exit = new QPushButton(registe);
        btn_register_exit->setObjectName(QString::fromUtf8("btn_register_exit"));

        horizontalLayout_11->addWidget(btn_register_exit);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        horizontalLayout_11->setStretch(0, 2);
        horizontalLayout_11->setStretch(1, 3);
        horizontalLayout_11->setStretch(3, 3);
        horizontalLayout_11->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_11);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);

        retranslateUi(registe);

        QMetaObject::connectSlotsByName(registe);
    } // setupUi

    void retranslateUi(QDialog *registe)
    {
        registe->setWindowTitle(QCoreApplication::translate("registe", "\346\226\260\345\273\272\347\224\250\346\210\267", nullptr));
        title->setText(QCoreApplication::translate("registe", "\346\226\260\345\273\272\347\224\250\346\210\267", nullptr));
        user_name->setText(QCoreApplication::translate("registe", "\345\270\220\345\217\267\357\274\232", nullptr));
        le_usernum->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\345\270\220\345\217\267", nullptr));
        pwd->setText(QCoreApplication::translate("registe", "\345\257\206\347\240\201\357\274\232", nullptr));
        le_pwd->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        sure_pwd->setText(QCoreApplication::translate("registe", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        le_surepwd->setPlaceholderText(QCoreApplication::translate("registe", "\345\206\215\346\254\241\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        lb_system_role->setText(QCoreApplication::translate("registe", "\347\263\273\347\273\237\350\247\222\350\211\262\357\274\232", nullptr));
        cbb_system_role->setItemText(0, QString());
        cbb_system_role->setItemText(1, QCoreApplication::translate("registe", "\346\225\231\347\273\203\345\221\230", nullptr));
        cbb_system_role->setItemText(2, QCoreApplication::translate("registe", "\345\217\227\350\256\255\350\200\205", nullptr));
        cbb_system_role->setItemText(3, QCoreApplication::translate("registe", "\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230", nullptr));

        lb_username->setText(QCoreApplication::translate("registe", "\345\247\223\345\220\215\357\274\232", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        lb_usersex->setText(QCoreApplication::translate("registe", "\346\200\247\345\210\253\357\274\232", nullptr));
        cbb_usersex->setItemText(0, QString());
        cbb_usersex->setItemText(1, QCoreApplication::translate("registe", "\347\224\267", nullptr));
        cbb_usersex->setItemText(2, QCoreApplication::translate("registe", "\345\245\263", nullptr));

        lb_organization->setText(QCoreApplication::translate("registe", "\346\234\272\346\236\204\357\274\232", nullptr));
        le_organization->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\346\234\272\346\236\204\345\220\215\347\247\260", nullptr));
        lb_origanization_code->setText(QCoreApplication::translate("registe", "\346\234\272\346\236\204\344\273\243\347\240\201\357\274\232", nullptr));
        le_origanization_code->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\346\234\272\346\236\204\344\273\243\347\240\201", nullptr));
        lb_duty->setText(QCoreApplication::translate("registe", "\350\201\214\345\212\241\357\274\232", nullptr));
        le_duty->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\350\201\214\345\212\241", nullptr));
        lb_duty_code->setText(QCoreApplication::translate("registe", "\350\201\214\345\212\241\344\273\243\347\240\201\357\274\232", nullptr));
        le_duty_code->setPlaceholderText(QCoreApplication::translate("registe", "\350\257\267\350\276\223\345\205\245\350\201\214\345\212\241\344\273\243\347\240\201", nullptr));
        btn_registe->setText(QCoreApplication::translate("registe", "\346\263\250\345\206\214", nullptr));
        btn_register_exit->setText(QCoreApplication::translate("registe", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registe: public Ui_registe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTE_H
