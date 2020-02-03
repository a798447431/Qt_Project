/********************************************************************************
** Form generated from reading UI file 'main_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_menu
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_mainmenu_help;
    QPushButton *btn_mainmenu_lockscreen;
    QPushButton *btn_mainmenu_minimize;
    QPushButton *btn_mainmenu_changpwd;
    QPushButton *btn_mainmenu_exit;
    QLabel *lb_find_title;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_userinfo_manage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_mainmenu_system_username;
    QLabel *lb_mainmenu_system_role;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lb_mainmenu_system_state;
    QSpacerItem *horizontalSpacer_12;
    QLabel *lb_mainmenu_system_time;

    void setupUi(QWidget *main_menu)
    {
        if (main_menu->objectName().isEmpty())
            main_menu->setObjectName(QString::fromUtf8("main_menu"));
        main_menu->resize(1085, 600);
        verticalLayout = new QVBoxLayout(main_menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_mainmenu_help = new QPushButton(main_menu);
        btn_mainmenu_help->setObjectName(QString::fromUtf8("btn_mainmenu_help"));

        horizontalLayout->addWidget(btn_mainmenu_help);

        btn_mainmenu_lockscreen = new QPushButton(main_menu);
        btn_mainmenu_lockscreen->setObjectName(QString::fromUtf8("btn_mainmenu_lockscreen"));

        horizontalLayout->addWidget(btn_mainmenu_lockscreen);

        btn_mainmenu_minimize = new QPushButton(main_menu);
        btn_mainmenu_minimize->setObjectName(QString::fromUtf8("btn_mainmenu_minimize"));

        horizontalLayout->addWidget(btn_mainmenu_minimize);

        btn_mainmenu_changpwd = new QPushButton(main_menu);
        btn_mainmenu_changpwd->setObjectName(QString::fromUtf8("btn_mainmenu_changpwd"));

        horizontalLayout->addWidget(btn_mainmenu_changpwd);

        btn_mainmenu_exit = new QPushButton(main_menu);
        btn_mainmenu_exit->setObjectName(QString::fromUtf8("btn_mainmenu_exit"));

        horizontalLayout->addWidget(btn_mainmenu_exit);


        verticalLayout->addLayout(horizontalLayout);

        lb_find_title = new QLabel(main_menu);
        lb_find_title->setObjectName(QString::fromUtf8("lb_find_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_find_title->sizePolicy().hasHeightForWidth());
        lb_find_title->setSizePolicy(sizePolicy);
        lb_find_title->setStyleSheet(QString::fromUtf8("font: 48pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        lb_find_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_find_title);

        verticalSpacer = new QSpacerItem(20, 54, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_userinfo_manage = new QPushButton(main_menu);
        btn_userinfo_manage->setObjectName(QString::fromUtf8("btn_userinfo_manage"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_userinfo_manage->sizePolicy().hasHeightForWidth());
        btn_userinfo_manage->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btn_userinfo_manage);

        horizontalSpacer_2 = new QSpacerItem(768, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lb_mainmenu_system_username = new QLabel(main_menu);
        lb_mainmenu_system_username->setObjectName(QString::fromUtf8("lb_mainmenu_system_username"));
        lb_mainmenu_system_username->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_mainmenu_system_username);

        lb_mainmenu_system_role = new QLabel(main_menu);
        lb_mainmenu_system_role->setObjectName(QString::fromUtf8("lb_mainmenu_system_role"));
        lb_mainmenu_system_role->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_mainmenu_system_role);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        lb_mainmenu_system_state = new QLabel(main_menu);
        lb_mainmenu_system_state->setObjectName(QString::fromUtf8("lb_mainmenu_system_state"));

        horizontalLayout_4->addWidget(lb_mainmenu_system_state);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        lb_mainmenu_system_time = new QLabel(main_menu);
        lb_mainmenu_system_time->setObjectName(QString::fromUtf8("lb_mainmenu_system_time"));
        sizePolicy1.setHeightForWidth(lb_mainmenu_system_time->sizePolicy().hasHeightForWidth());
        lb_mainmenu_system_time->setSizePolicy(sizePolicy1);
        lb_mainmenu_system_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_mainmenu_system_time);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 5);
        verticalLayout->setStretch(4, 1);

        retranslateUi(main_menu);

        QMetaObject::connectSlotsByName(main_menu);
    } // setupUi

    void retranslateUi(QWidget *main_menu)
    {
        main_menu->setWindowTitle(QCoreApplication::translate("main_menu", "Form", nullptr));
        btn_mainmenu_help->setText(QCoreApplication::translate("main_menu", "\345\270\256\345\212\251", nullptr));
        btn_mainmenu_lockscreen->setText(QCoreApplication::translate("main_menu", "\351\224\201\345\261\217", nullptr));
        btn_mainmenu_minimize->setText(QCoreApplication::translate("main_menu", "\346\234\200\345\260\217\345\214\226", nullptr));
        btn_mainmenu_changpwd->setText(QCoreApplication::translate("main_menu", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btn_mainmenu_exit->setText(QCoreApplication::translate("main_menu", "\351\200\200\345\207\272", nullptr));
        lb_find_title->setText(QCoreApplication::translate("main_menu", "\350\210\271\350\210\266**\346\250\241\346\213\237\350\256\255\347\273\203\347\263\273\347\273\237", nullptr));
        btn_userinfo_manage->setText(QCoreApplication::translate("main_menu", "\347\224\250\346\210\267\347\256\241\347\220\206\351\241\265\351\235\242", nullptr));
        lb_mainmenu_system_username->setText(QString());
        lb_mainmenu_system_role->setText(QString());
        lb_mainmenu_system_state->setText(QString());
        lb_mainmenu_system_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_menu: public Ui_main_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
