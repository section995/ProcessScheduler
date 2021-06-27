#include "exec_window.h"
#include "ui_exec_window.h"
#include "fcfs.h"
#include "sjf.h"
#include "rr.h"
#include "hrn.h"

exec_window::exec_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exec_window)
{
    ui->setupUi(this);
    ui->table_result->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->btn_ret, SIGNAL(clicked(bool)), this, SLOT(ret_previous()));
}

exec_window::~exec_window()
{
    delete ui;
}

void exec_window::select_schedule_mode(QString mode)
{
    this->mode = mode;
    ui->label->setText(QString::fromLocal8Bit("当前使用的进程调度算法是：") + mode);
    if(mode=="FCFS")
    {
        FCFS fcfs(jobs);
        fcfs.execute(ui->table_result, ui->list_process);
    }
    else if(mode=="SJF")
    {
        SJF sjf(jobs);
        sjf.execute(ui->table_result, ui->list_process);
    }
    else if(mode == "RR")
    {
        RR rr(jobs, 1);
        rr.execute(ui->table_result, ui->list_process);
    }
    else if(mode == "HRN")
    {
        HRN hrn(jobs);
        hrn.execute(ui->table_result, ui->list_process);
    }
}

void exec_window::get_job_list(NodeList<Job> jobs)
{
    this->jobs.AddNodeList(jobs);
}

void exec_window::ret_previous()
{
    this->close();
}
