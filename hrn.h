#ifndef HRN_H
#define HRN_H

#include "exec_window.h"
#include "LinkList.h"
#include "Job.h"
#include <QTableWidget>
#include <QListWidget>

class HRN {
public:
    //构造函数
    HRN(NodeList<Job> jobs) : list(jobs) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //执行
    void execute(QTableWidget*, QListWidget*);
private:
    NodeList<Job> list;
};

#endif // HRN_H
