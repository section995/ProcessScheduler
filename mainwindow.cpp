#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exec_window.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table_input->setColumnCount(3);
    QStringList header;
    header<<QString::fromLocal8Bit("作业号")<<QString::fromLocal8Bit("到达时间")<<QString::fromLocal8Bit("执行时间");
    ui->table_input->setHorizontalHeaderLabels(header);

     ui->btn_exec->setDisabled(true);

    connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(set_table()));
    connect(ui->btn_exec, SIGNAL(clicked(bool)), this, SLOT(into_exec_window()));
    connect(ui->btn_import, SIGNAL(clicked(bool)), this, SLOT(import_file()));
    connect(ui->btn_clear, SIGNAL(clicked(bool)), this, SLOT(clear_table()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_table()
{
    if(ui->le_jobcount->text().toInt()<=0||ui->le_jobcount->text()==NULL) {
        QMessageBox::critical(this, QString::fromLocal8Bit("非法输入"), QString::fromLocal8Bit("请输入正确的作业数量"), QString::fromLocal8Bit("确认"));
    }
    else {
        rowCnt = ui->le_jobcount->text().toInt();
        ui->le_jobcount->clear();
        QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("设置作业数量成功"), QString::fromLocal8Bit("确认"));
        ui->table_input->setRowCount(rowCnt);
        ui->table_input->setEditTriggers(QAbstractItemView::DoubleClicked);
        for(int i=0;i<rowCnt;i++) {
            for(int j=0;j<3;j++)
                ui->table_input->setItem(i, j, new QTableWidgetItem(NULL));
        }
        ui->btn_exec->setEnabled(true);
    }
}

void MainWindow::into_exec_window()
{
    NodeList<Job> jobs;     //作业表
    Job job;
    jobs.SetCompareFunction(jobSortArrivalTime);
    for(int i=0;i<rowCnt;i++) {
        QTableWidgetItem * item = ui->table_input->item(i, 0);
        job.jobId = item->text().toStdString();
        item = ui->table_input->item(i, 1);
        job.arrivalTime = item->text().toUInt();
        item = ui->table_input->item(i, 2);
        job.executionTime = item->text().toUInt();
        jobs.Insert(jobs.GetLength(), job, true);
    }
    if(ui->comboBox->currentIndex() == 0)   {
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请选择进程调度方式！"));
        return;
    }
    e_w = new exec_window;
    e_w->show();
    connect(this, SIGNAL(send_job_list(NodeList<Job>)), e_w, SLOT(get_job_list(NodeList<Job>)));
    emit send_job_list(jobs);
    connect(this, SIGNAL(send_schedule_mode(QString)), e_w, SLOT(select_schedule_mode(QString)));
    emit send_schedule_mode(ui->comboBox->currentText());
}

void MainWindow::import_file()
{
     QFile file("C://Users//10437//ProcessScheduler//data.txt");
     if(!file.exists()) {
         QMessageBox::information(this, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("data.txt不存在！"));
     }
     else if(!file.open(QIODevice :: ReadOnly | QIODevice :: Text)) {
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法打开data.txt"));
    }
//    char str[45];
//    //将首行读出
//    file.readLine(str, 45);

    QTextStream in(&file);
    int currentRow = 0;
    rowCnt = 0;
    while(!in.atEnd())
    {
        QStringList list = in.readLine().split("\t");
//        qDebug()<<list;
        ui->table_input->insertRow(currentRow);
        for(int j=0;j<3;j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(list[j]);
            ui->table_input->setItem(currentRow, j, item);
        }
        currentRow++;
        rowCnt++;
    }
    file.close();

    ui->btn_exec->setEnabled(true);
}

void MainWindow::clear_table()
{
    for(int i=0;i<rowCnt;i++)
        ui->table_input->removeRow(0);
    QStringList header;
    header<<QString::fromLocal8Bit("作业号")<<QString::fromLocal8Bit("到达时间")<<QString::fromLocal8Bit("执行时间");
    ui->table_input->setHorizontalHeaderLabels(header);

    ui->btn_exec->setDisabled(true);
}
