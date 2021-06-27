#include "rr.h"
#include "exec_window.h"
#include <QStringList>

void RR::execute(QTableWidget *result_tab, QListWidget *process_list)
{
    if(list.GetLength() == 0) {
        process_list->addItem(QString::fromLocal8Bit("任务表为空！"));
        return;
    }
    Job job;
    NodeList<JobPack> arrived;
    JobPack jp;
    //当前时间, 总数
    unsigned int now = 0, total = 0, sum;
    int currentRow=0;

    result_tab->setColumnCount(4);
    result_tab->setRowCount(list.GetLength());
    sum = result_tab->rowCount();

    QStringList header;
    header<<QString::fromLocal8Bit("执行完的作业")<<QString::fromLocal8Bit("完成时间")
         <<QString::fromLocal8Bit("周转时间")<<QString::fromLocal8Bit("带权周转时间");
    result_tab->setHorizontalHeaderLabels(header);

    while(list.GetLength() > 0 || arrived.GetLength() > 0 ||
          total == sum - 1)
    {
        while(list.GetLength() > 0) {
            list.Find(0, job);
            if(job.arrivalTime <= now) {
                //已到达的列表，不排序
                arrived.Insert(arrived.GetLength(), {job, 0});
                list.Delete(0);

                // 输出日志
                QString str = QString::fromLocal8Bit("号进程参与调度");
                QString current_job = QString::fromStdString(job.jobId);
                str = current_job + str;
                process_list->addItem(str);

                continue;
            }
            break;
        }
        if(now != 0 && jp.job.executionTime > jp.operated) {
            arrived.Insert(arrived.GetLength(), jp);
        }
        if(now < job.arrivalTime && arrived.GetLength() == 0) {
            now = job.arrivalTime;
            arrived.Insert(arrived.GetLength(), {job, 0});
            list.Delete(0);            
        }
        arrived.Find(0, jp);
        arrived.Delete(0);
        job = jp.job;

        if(job.executionTime - jp.operated < slice) {
             now += job.executionTime - jp.operated;
             QString str;
             str = QString::fromStdString(job.jobId) + QString::fromLocal8Bit("号作业执行了") + QVariant(slice).toString() + QString::fromLocal8Bit("个时间片");
             process_list->addItem(str);
             jp.operated = job.executionTime;
         } else {
             now += slice;
             QString str;
             str = QString::fromStdString(job.jobId) + QString::fromLocal8Bit("号作业执行了") + QVariant(slice).toString() + QString::fromLocal8Bit("个时间片");
             process_list->addItem(str);
             jp.operated += slice;
         }
         if(job.executionTime <= jp.operated) {
             QString str;
             str = QString::fromStdString(job.jobId) + QString::fromLocal8Bit("号作业执行完成");
             process_list->addItem(str);
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
             total++;
         }
    }
}
