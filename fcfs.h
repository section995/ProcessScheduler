#ifndef FCFS_H
#define FCFS_H
#include "exec_window.h"
#include "LinkList.h"
#include "Job.h"
#include <QTableWidget>
#include <QListWidget>

class FCFS {
public:
    //构造函数
    FCFS(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //执行
    void execute(QTableWidget*, QListWidget*);
private:
    NodeList<Job> list;
};

#endif // FCFS_H
