#include "hrn.h"
#include "exec_window.h"
#include <QStringList>
#include <QDebug>

void HRN::execute(QTableWidget *result_tab, QListWidget *process_list)
{
    if(list.GetLength() == 0) {
        process_list->addItem(QString::fromLocal8Bit("任务表为空！"));
        return;
    }
    Job job;
    NodeList<Job> arrived;
    arrived.SetCompareFunction(jobSortPriority);
    //当前时间，总数
    unsigned int now = 0;
    int currentRow=0;

    result_tab->setColumnCount(4);
    result_tab->setRowCount(list.GetLength());

    QStringList header;
    header<<QString::fromLocal8Bit("执行完的作业")<<QString::fromLocal8Bit("完成时间")
         <<QString::fromLocal8Bit("周转时间")<<QString::fromLocal8Bit("带权周转时间");
    result_tab->setHorizontalHeaderLabels(header);

    while(list.GetLength() > 0 || arrived.GetLength() > 0) {
        while(list.GetLength() > 0) {
            list.Find(0, job);
            if(job.arrivalTime <= now) {
                //已到达的列表，按响应比排序
                Job job_t;
                for(int i=0;i<arrived.GetLength();i++)  {
                    arrived.Find(0, job_t);
                    arrived.Delete(0);
                    job_t.waitTime = now - job_t.arrivalTime;
                    if(i == arrived.GetLength())    {
                        arrived.Insert(arrived.GetLength(), job_t, true);
                    }
                    else
                        arrived.Insert(arrived.GetLength(), job_t, false);
                }
                job.waitTime = now - job.arrivalTime;
                arrived.Insert(arrived.GetLength(), job, true);
//                qDebug()<<"all of the jobs:";
//                for(int i=0;i<arrived.GetLength();i++)
//                {
//                    arrived.Find(i, job);
//                    qDebug()<<job.jobId<<job.waitTime;
//                }
                list.Delete(0);
                continue;
            }
            break;
        }
        if(now < job.arrivalTime && arrived.GetLength() == 0) {
            now = job.arrivalTime;
            list.Delete(0);
            // 输出队列
            QString str = QString::fromLocal8Bit("当前队列内排队的进程有：") + QString::fromStdString(job.jobId);
            process_list->addItem(str);
        } else {
            //输出队列
            Job job_t;
            QString str = QString::fromLocal8Bit("当前队列内排队的进程有：");
            for(int i=0;i<arrived.GetLength();i++)
            {
                arrived.Find(i,job_t);
                QString current_job = QString::fromStdString(job_t.jobId) + " ";
                str = str + current_job;
            }
            process_list->addItem(str);

            arrived.Find(0, job);
            arrived.Delete(0);
        }
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
        currentRow++;
    }
}
