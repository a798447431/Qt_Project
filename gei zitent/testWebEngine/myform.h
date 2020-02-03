#ifndef MYFORM_H
#define MYFORM_H

#include <QWidget>
#include <QWebEngineView>
#include <QVBoxLayout>

namespace Ui {
class MyForm;
}
class WebObject;
class MyForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyForm(QWidget *parent = 0);
    ~MyForm();

private slots:
    void on_okBtn_clicked();

    void on_pushButton_clicked();

    void on_callJsBtn_clicked();

private:
    Ui::MyForm *ui;
    WebObject * m_dataObj;
    QWebEngineView *webview ;
    QWebEngineView * m_webview;
    QVBoxLayout *m_vboxlayout;
    QWidget * m_widget;

//    QString jQuery;
};

#endif // MYFORM_H

