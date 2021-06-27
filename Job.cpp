#include "Job.h"

//按到达时间排序函数
int jobSortArrivalTime(Job& left, Job& right) {
    int x = left.arrivalTime - right.arrivalTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
//按执行时间长短排序函数
int jobSortExecutionTime(Job& left, Job& right) {
    int x = left.executionTime - right.executionTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
//按响应比排序函数
int jobSortPriority(Job& left, Job& right) {
    left.priority = (double)left.waitTime/left.executionTime;
    right.priority = (double)right.waitTime/left.executionTime;
    double x = left.priority - right.priority;
    return x < 0 ? 1 : x > 0 ? -1 : 0;
}
