#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "exec_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void send_schedule_mode(QString);
    void send_job_list(NodeList<Job>);

private slots:
    void set_table();
    void into_exec_window();
    void import_file();
    void clear_table();

private:
    Ui::MainWindow *ui;
    int rowCnt;
    exec_window * e_w;
};
#endif // MAINWINDOW_H
