#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QModelIndex>
#include <QVector>

class QSqlDatabase;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void sortByColumn(int col);

private slots:
    void on_pushButton_save_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_del_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase _db;
};

#endif // MAINWINDOW_H
