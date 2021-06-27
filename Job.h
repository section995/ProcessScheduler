#ifndef JOB_H
#define JOB_H
#include <string>
using namespace std;

struct Job {
    //作业ID
    string jobId;
    //到达时间
    unsigned int arrivalTime;
    //执行时间
    unsigned int executionTime;
    //响应比
    double priority=0;
    //等待时间，用于HRN算法
    unsigned int waitTime=0;
};


//按到达时间排序函数
int jobSortArrivalTime(Job&, Job&);

//按执行时间长短排序函数
int jobSortExecutionTime(Job&, Job&);

//按响应比排序函数
int jobSortPriority(Job&, Job&);

#endif // JOB_H
