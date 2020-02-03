#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
QT_BEGIN_NAMESPACE
class QWebEngineView;
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainForm *ui;
    QString jQuery;
    QWebEngineView *pv;
    int progress;
};

#endif // MAINFORM_H
