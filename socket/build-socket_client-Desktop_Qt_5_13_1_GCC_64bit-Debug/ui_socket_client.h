/********************************************************************************
** Form generated from reading UI file 'socket_client.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKET_CLIENT_H
#define UI_SOCKET_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_socket_client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_server_ip;
    QLabel *label_2;
    QLineEdit *le_server_port;
    QPushButton *btn_bind;
    QTextEdit *te_server;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_send;
    QTextEdit *te_client;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *socket_client)
    {
        if (socket_client->objectName().isEmpty())
            socket_client->setObjectName(QString::fromUtf8("socket_client"));
        socket_client->resize(643, 497);
        centralWidget = new QWidget(socket_client);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        le_server_ip = new QLineEdit(centralWidget);
        le_server_ip->setObjectName(QString::fromUtf8("le_server_ip"));

        horizontalLayout->addWidget(le_server_ip);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        le_server_port = new QLineEdit(centralWidget);
        le_server_port->setObjectName(QString::fromUtf8("le_server_port"));

        horizontalLayout->addWidget(le_server_port);

        btn_bind = new QPushButton(centralWidget);
        btn_bind->setObjectName(QString::fromUtf8("btn_bind"));

        horizontalLayout->addWidget(btn_bind);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        te_server = new QTextEdit(centralWidget);
        te_server->setObjectName(QString::fromUtf8("te_server"));

        gridLayout->addWidget(te_server, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_send = new QPushButton(centralWidget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        horizontalLayout_2->addWidget(btn_send);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        te_client = new QTextEdit(centralWidget);
        te_client->setObjectName(QString::fromUtf8("te_client"));

        gridLayout->addWidget(te_client, 3, 0, 1, 1);

        socket_client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(socket_client);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 28));
        socket_client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(socket_client);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        socket_client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(socket_client);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        socket_client->setStatusBar(statusBar);

        retranslateUi(socket_client);

        QMetaObject::connectSlotsByName(socket_client);
    } // setupUi

    void retranslateUi(QMainWindow *socket_client)
    {
        socket_client->setWindowTitle(QCoreApplication::translate("socket_client", "socket_client", nullptr));
        label->setText(QCoreApplication::translate("socket_client", "server_ip", nullptr));
        le_server_ip->setText(QCoreApplication::translate("socket_client", "192.168.3.13", nullptr));
        label_2->setText(QCoreApplication::translate("socket_client", "server_port", nullptr));
        le_server_port->setText(QCoreApplication::translate("socket_client", "9999", nullptr));
        btn_bind->setText(QCoreApplication::translate("socket_client", "\351\223\276\346\216\245", nullptr));
        btn_send->setText(QCoreApplication::translate("socket_client", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class socket_client: public Ui_socket_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKET_CLIENT_H
