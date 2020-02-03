/********************************************************************************
** Form generated from reading UI file 'socket_server.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKET_SERVER_H
#define UI_SOCKET_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_socket_server
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
    QLabel *label_4;
    QLineEdit *le_client_ip;
    QLabel *label_3;
    QLineEdit *le_client_port;
    QPushButton *btn_send;
    QTextEdit *te_client;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *socket_server)
    {
        if (socket_server->objectName().isEmpty())
            socket_server->setObjectName(QString::fromUtf8("socket_server"));
        socket_server->resize(625, 409);
        centralWidget = new QWidget(socket_server);
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
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        le_client_ip = new QLineEdit(centralWidget);
        le_client_ip->setObjectName(QString::fromUtf8("le_client_ip"));

        horizontalLayout_2->addWidget(le_client_ip);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        le_client_port = new QLineEdit(centralWidget);
        le_client_port->setObjectName(QString::fromUtf8("le_client_port"));

        horizontalLayout_2->addWidget(le_client_port);

        btn_send = new QPushButton(centralWidget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        horizontalLayout_2->addWidget(btn_send);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        te_client = new QTextEdit(centralWidget);
        te_client->setObjectName(QString::fromUtf8("te_client"));

        gridLayout->addWidget(te_client, 3, 0, 1, 1);

        socket_server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(socket_server);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 625, 28));
        socket_server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(socket_server);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        socket_server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(socket_server);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        socket_server->setStatusBar(statusBar);

        retranslateUi(socket_server);

        QMetaObject::connectSlotsByName(socket_server);
    } // setupUi

    void retranslateUi(QMainWindow *socket_server)
    {
        socket_server->setWindowTitle(QCoreApplication::translate("socket_server", "socket_server", nullptr));
        label->setText(QCoreApplication::translate("socket_server", "server_ip", nullptr));
        le_server_ip->setText(QCoreApplication::translate("socket_server", "192.168.3.13", nullptr));
        label_2->setText(QCoreApplication::translate("socket_server", "server_port", nullptr));
        le_server_port->setText(QCoreApplication::translate("socket_server", "9999", nullptr));
        btn_bind->setText(QCoreApplication::translate("socket_server", "\347\273\221\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("socket_server", "client_ip", nullptr));
        label_3->setText(QCoreApplication::translate("socket_server", "client_port", nullptr));
        btn_send->setText(QCoreApplication::translate("socket_server", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class socket_server: public Ui_socket_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKET_SERVER_H
