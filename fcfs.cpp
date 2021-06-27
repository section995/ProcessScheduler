#include "FCFS.h"
#include "exec_window.h"
#include <QStringList>
#include <QString>

//执行
void FCFS::execute(QTableWidget *result_tab, QListWidget *process_list) {
    if(list.GetLength() == 0) {
        process_list->addItem(QString::fromLocal8Bit("任务表为空！"));
        return;
    }
    Job job;
    //当前时间，总数
    unsigned int now = 0;
    int currentRow = 0;
//    //总等待时间，总周转时间，总带权周转时间
//    double totalWait = 0, totalTurnover = 0, totalRightTurnover = 0;
    result_tab->setColumnCount(4);
    result_tab->setRowCount(list.GetLength());

    QStringList header;
    header<<QString::fromLocal8Bit("执行完的作业")<<QString::fromLocal8Bit("完成时间")
         <<QString::fromLocal8Bit("周转时间")<<QString::fromLocal8Bit("带权周转时间");
    result_tab->setHorizontalHeaderLabels(header);

    while(list.GetLength() > 0) {
        list.Find(0, job);
        if(now < job.arrivalTime) {
            now = job.arrivalTime;
        }
        //输出队列
        Job job_t;
        QString str = QString::fromLocal8Bit("当前队列内排队的进程有：");
        for(int i=0;i<list.GetLength();i++)
        {
            list.Find(i,job_t);
            if(job_t.arrivalTime <= now)
            {
                QString current_job = QString::fromStdString(job_t.jobId) + " ";
                str = str + current_job;
            }
        }
        process_list->addItem(str);

        now += job.executionTime;

        QTableWidgetItem *item1,*item2,*item3,*item4;
        item1 = new QTableWidgetItem(QString::fromStdString(job.jobId));    //执行完的作业
        item2 = new QTableWidgetItem(QVariant(now).toString());    //完成时间
        item3 = new QTableWidgetItem(QVariant(now - job.arrivalTime).toString());    //周转时间
        item4 = new QTableWidgetItem(QVariant(double(now - job.arrivalTime)/job.executionTime).toString());    //带权周转时间
        result_tab->setItem(currentRow, 0, item1);
        result_tab->setItem(currentRow, 1, item2);
        result_tab->setItem(currentRow, 2, item3);
        result_tab->setItem(currentRow, 3, item4);

        list.Delete(0);
        currentRow++;
    }
}
