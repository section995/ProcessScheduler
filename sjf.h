#ifndef SJF_H
#define SJF_H

#include "exec_window.h"
#include "LinkList.h"
#include "Job.h"
#include <QTableWidget>
#include <QListWidget>

class SJF
{
public:
    SJF(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //执行
    void execute(QTableWidget*, QListWidget*);
private:
    NodeList<Job> list;
};

#endif // SJF_H
