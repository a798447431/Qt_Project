/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainmenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_help;
    QPushButton *btn_lockscreen;
    QPushButton *btn_minimize;
    QPushButton *btn_changpwd;
    QPushButton *btn_exit;
    QLabel *lb_find_title;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *le_find_organization;
    QLabel *lb_find_duty;
    QLineEdit *le_find_organization_code;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lb_find_username;
    QLabel *lb_find_duty_code;
    QLabel *lb_find_organization_code;
    QLineEdit *le_find_duty;
    QLineEdit *le_find_username;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *cb_find_usersex;
    QLabel *lb_find_organization;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *le_find_duty_code;
    QLabel *lb_find_usersex;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *btn_delete;
    QPushButton *btn_registe;
    QPushButton *btn_findinfo;
    QPushButton *btn_resetting;
    QPushButton *btn_edit;
    QPushButton *btn_return;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_pagehome;
    QPushButton *btn_pageup;
    QSpacerItem *horizontalSpacer_11;
    QLabel *lb_now_page_num;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_pagedown;
    QPushButton *btn_end;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_system_username;
    QLabel *lb_system_role;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lb_system_state;
    QSpacerItem *horizontalSpacer_12;
    QLabel *lb_system_time;
    QMenuBar *menubar;

    void setupUi(QMainWindow *mainmenu)
    {
        if (mainmenu->objectName().isEmpty())
            mainmenu->setObjectName(QString::fromUtf8("mainmenu"));
        mainmenu->setWindowModality(Qt::NonModal);
        mainmenu->resize(1085, 600);
        centralwidget = new QWidget(mainmenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_help = new QPushButton(centralwidget);
        btn_help->setObjectName(QString::fromUtf8("btn_help"));

        horizontalLayout->addWidget(btn_help);

        btn_lockscreen = new QPushButton(centralwidget);
        btn_lockscreen->setObjectName(QString::fromUtf8("btn_lockscreen"));

        horizontalLayout->addWidget(btn_lockscreen);

        btn_minimize = new QPushButton(centralwidget);
        btn_minimize->setObjectName(QString::fromUtf8("btn_minimize"));

        horizontalLayout->addWidget(btn_minimize);

        btn_changpwd = new QPushButton(centralwidget);
        btn_changpwd->setObjectName(QString::fromUtf8("btn_changpwd"));

        horizontalLayout->addWidget(btn_changpwd);

        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout->addLayout(horizontalLayout);

        lb_find_title = new QLabel(centralwidget);
        lb_find_title->setObjectName(QString::fromUtf8("lb_find_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_find_title->sizePolicy().hasHeightForWidth());
        lb_find_title->setSizePolicy(sizePolicy);
        lb_find_title->setStyleSheet(QString::fromUtf8("font: 48pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        lb_find_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_find_title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        le_find_organization = new QLineEdit(centralwidget);
        le_find_organization->setObjectName(QString::fromUtf8("le_find_organization"));

        gridLayout_2->addWidget(le_find_organization, 1, 4, 1, 1);

        lb_find_duty = new QLabel(centralwidget);
        lb_find_duty->setObjectName(QString::fromUtf8("lb_find_duty"));
        lb_find_duty->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_duty, 1, 6, 1, 1);

        le_find_organization_code = new QLineEdit(centralwidget);
        le_find_organization_code->setObjectName(QString::fromUtf8("le_find_organization_code"));

        gridLayout_2->addWidget(le_find_organization_code, 2, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        lb_find_username = new QLabel(centralwidget);
        lb_find_username->setObjectName(QString::fromUtf8("lb_find_username"));
        lb_find_username->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_username, 1, 0, 1, 1);

        lb_find_duty_code = new QLabel(centralwidget);
        lb_find_duty_code->setObjectName(QString::fromUtf8("lb_find_duty_code"));
        lb_find_duty_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_duty_code, 2, 6, 1, 1);

        lb_find_organization_code = new QLabel(centralwidget);
        lb_find_organization_code->setObjectName(QString::fromUtf8("lb_find_organization_code"));
        lb_find_organization_code->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_organization_code, 2, 3, 1, 1);

        le_find_duty = new QLineEdit(centralwidget);
        le_find_duty->setObjectName(QString::fromUtf8("le_find_duty"));

        gridLayout_2->addWidget(le_find_duty, 1, 7, 1, 1);

        le_find_username = new QLineEdit(centralwidget);
        le_find_username->setObjectName(QString::fromUtf8("le_find_username"));

        gridLayout_2->addWidget(le_find_username, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 5, 1, 1);

        cb_find_usersex = new QComboBox(centralwidget);
        cb_find_usersex->addItem(QString());
        cb_find_usersex->addItem(QString());
        cb_find_usersex->addItem(QString());
        cb_find_usersex->setObjectName(QString::fromUtf8("cb_find_usersex"));

        gridLayout_2->addWidget(cb_find_usersex, 2, 1, 1, 1);

        lb_find_organization = new QLabel(centralwidget);
        lb_find_organization->setObjectName(QString::fromUtf8("lb_find_organization"));
        lb_find_organization->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_organization, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        le_find_duty_code = new QLineEdit(centralwidget);
        le_find_duty_code->setObjectName(QString::fromUtf8("le_find_duty_code"));

        gridLayout_2->addWidget(le_find_duty_code, 2, 7, 1, 1);

        lb_find_usersex = new QLabel(centralwidget);
        lb_find_usersex->setObjectName(QString::fromUtf8("lb_find_usersex"));
        lb_find_usersex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lb_find_usersex, 2, 0, 1, 1);

        gridLayout_2->setColumnStretch(1, 3);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);
        gridLayout_2->setColumnStretch(4, 3);
        gridLayout_2->setColumnStretch(5, 1);
        gridLayout_2->setColumnStretch(6, 1);
        gridLayout_2->setColumnStretch(7, 3);

        horizontalLayout_2->addLayout(gridLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_delete = new QPushButton(centralwidget);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        gridLayout->addWidget(btn_delete, 0, 2, 1, 1);

        btn_registe = new QPushButton(centralwidget);
        btn_registe->setObjectName(QString::fromUtf8("btn_registe"));

        gridLayout->addWidget(btn_registe, 1, 0, 1, 1);

        btn_findinfo = new QPushButton(centralwidget);
        btn_findinfo->setObjectName(QString::fromUtf8("btn_findinfo"));

        gridLayout->addWidget(btn_findinfo, 0, 0, 1, 1);

        btn_resetting = new QPushButton(centralwidget);
        btn_resetting->setObjectName(QString::fromUtf8("btn_resetting"));

        gridLayout->addWidget(btn_resetting, 0, 1, 1, 1);

        btn_edit = new QPushButton(centralwidget);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));

        gridLayout->addWidget(btn_edit, 1, 1, 1, 1);

        btn_return = new QPushButton(centralwidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));

        gridLayout->addWidget(btn_return, 1, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        btn_pagehome = new QPushButton(centralwidget);
        btn_pagehome->setObjectName(QString::fromUtf8("btn_pagehome"));

        horizontalLayout_3->addWidget(btn_pagehome);

        btn_pageup = new QPushButton(centralwidget);
        btn_pageup->setObjectName(QString::fromUtf8("btn_pageup"));

        horizontalLayout_3->addWidget(btn_pageup);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        lb_now_page_num = new QLabel(centralwidget);
        lb_now_page_num->setObjectName(QString::fromUtf8("lb_now_page_num"));
        lb_now_page_num->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lb_now_page_num);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        btn_pagedown = new QPushButton(centralwidget);
        btn_pagedown->setObjectName(QString::fromUtf8("btn_pagedown"));

        horizontalLayout_3->addWidget(btn_pagedown);

        btn_end = new QPushButton(centralwidget);
        btn_end->setObjectName(QString::fromUtf8("btn_end"));

        horizontalLayout_3->addWidget(btn_end);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(4, 1);
        horizontalLayout_3->setStretch(6, 1);
        horizontalLayout_3->setStretch(7, 1);
        horizontalLayout_3->setStretch(8, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lb_system_username = new QLabel(centralwidget);
        lb_system_username->setObjectName(QString::fromUtf8("lb_system_username"));
        lb_system_username->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_system_username);

        lb_system_role = new QLabel(centralwidget);
        lb_system_role->setObjectName(QString::fromUtf8("lb_system_role"));
        lb_system_role->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_system_role);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        lb_system_state = new QLabel(centralwidget);
        lb_system_state->setObjectName(QString::fromUtf8("lb_system_state"));

        horizontalLayout_4->addWidget(lb_system_state);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        lb_system_time = new QLabel(centralwidget);
        lb_system_time->setObjectName(QString::fromUtf8("lb_system_time"));
        lb_system_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lb_system_time);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        mainmenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainmenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1085, 25));
        mainmenu->setMenuBar(menubar);

        retranslateUi(mainmenu);

        QMetaObject::connectSlotsByName(mainmenu);
    } // setupUi

    void retranslateUi(QMainWindow *mainmenu)
    {
        mainmenu->setWindowTitle(QCoreApplication::translate("mainmenu", "\350\210\271\350\210\266**\346\250\241\346\213\237\350\256\255\347\273\203\347\263\273\347\273\237", nullptr));
        btn_help->setText(QCoreApplication::translate("mainmenu", "\345\270\256\345\212\251", nullptr));
        btn_lockscreen->setText(QCoreApplication::translate("mainmenu", "\351\224\201\345\261\217", nullptr));
        btn_minimize->setText(QCoreApplication::translate("mainmenu", "\346\234\200\345\260\217\345\214\226", nullptr));
        btn_changpwd->setText(QCoreApplication::translate("mainmenu", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        btn_exit->setText(QCoreApplication::translate("mainmenu", "\351\200\200\345\207\272", nullptr));
        lb_find_title->setText(QCoreApplication::translate("mainmenu", "\350\210\271\350\210\266**\346\250\241\346\213\237\350\256\255\347\273\203\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("mainmenu", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        lb_find_duty->setText(QCoreApplication::translate("mainmenu", "\350\201\214\345\212\241", nullptr));
        lb_find_username->setText(QCoreApplication::translate("mainmenu", "\345\247\223\345\220\215", nullptr));
        lb_find_duty_code->setText(QCoreApplication::translate("mainmenu", "\350\201\214\345\212\241\344\273\243\347\240\201", nullptr));
        lb_find_organization_code->setText(QCoreApplication::translate("mainmenu", "\346\234\272\346\236\204\344\273\243\347\240\201", nullptr));
        cb_find_usersex->setItemText(0, QString());
        cb_find_usersex->setItemText(1, QCoreApplication::translate("mainmenu", "\347\224\267", nullptr));
        cb_find_usersex->setItemText(2, QCoreApplication::translate("mainmenu", "\345\245\263", nullptr));

        lb_find_organization->setText(QCoreApplication::translate("mainmenu", "\346\234\272\346\236\204", nullptr));
        lb_find_usersex->setText(QCoreApplication::translate("mainmenu", "\346\200\247\345\210\253", nullptr));
        btn_delete->setText(QCoreApplication::translate("mainmenu", "\345\210\240\351\231\244", nullptr));
        btn_registe->setText(QCoreApplication::translate("mainmenu", "\346\226\260\345\273\272", nullptr));
        btn_findinfo->setText(QCoreApplication::translate("mainmenu", "\346\237\245\350\257\242", nullptr));
        btn_resetting->setText(QCoreApplication::translate("mainmenu", "\351\207\215\347\275\256", nullptr));
        btn_edit->setText(QCoreApplication::translate("mainmenu", "\344\277\256\346\224\271", nullptr));
        btn_return->setText(QCoreApplication::translate("mainmenu", "\350\277\224\345\233\236", nullptr));
        btn_pagehome->setText(QCoreApplication::translate("mainmenu", "\351\246\226\351\241\265", nullptr));
        btn_pageup->setText(QCoreApplication::translate("mainmenu", "\344\270\212\344\270\200\351\241\265", nullptr));
        lb_now_page_num->setText(QCoreApplication::translate("mainmenu", "\347\254\2541\351\241\265", nullptr));
        btn_pagedown->setText(QCoreApplication::translate("mainmenu", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_end->setText(QCoreApplication::translate("mainmenu", "\346\234\253\351\241\265", nullptr));
        lb_system_username->setText(QString());
        lb_system_role->setText(QString());
        lb_system_state->setText(QString());
        lb_system_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainmenu: public Ui_mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
