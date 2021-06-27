#ifndef EXEC_WINDOW_H
#define EXEC_WINDOW_H

#include <QDialog>
#include "LinkList.h"
#include "Job.h"

namespace Ui {
class exec_window;
}

class exec_window : public QDialog
{
    Q_OBJECT

public:
    explicit exec_window(QWidget *parent = nullptr);
    ~exec_window();

private slots:
    void select_schedule_mode(QString mode);
    void get_job_list(NodeList<Job>);
    void ret_previous();

private:
    Ui::exec_window *ui;
    NodeList<Job> jobs;
    QString mode=NULL;
};

#endif // EXEC_WINDOW_H
