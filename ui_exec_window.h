/********************************************************************************
** Form generated from reading UI file 'exec_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXEC_WINDOW_H
#define UI_EXEC_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_exec_window
{
public:
    QListWidget *list_process;
    QTableWidget *table_result;
    QPushButton *btn_ret;
    QLabel *label;

    void setupUi(QDialog *exec_window)
    {
        if (exec_window->objectName().isEmpty())
            exec_window->setObjectName(QStringLiteral("exec_window"));
        exec_window->resize(825, 595);
        list_process = new QListWidget(exec_window);
        list_process->setObjectName(QStringLiteral("list_process"));
        list_process->setGeometry(QRect(460, 70, 341, 471));
        table_result = new QTableWidget(exec_window);
        table_result->setObjectName(QStringLiteral("table_result"));
        table_result->setGeometry(QRect(10, 70, 421, 471));
        btn_ret = new QPushButton(exec_window);
        btn_ret->setObjectName(QStringLiteral("btn_ret"));
        btn_ret->setGeometry(QRect(370, 550, 91, 31));
        label = new QLabel(exec_window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 20, 221, 31));

        retranslateUi(exec_window);

        QMetaObject::connectSlotsByName(exec_window);
    } // setupUi

    void retranslateUi(QDialog *exec_window)
    {
        exec_window->setWindowTitle(QApplication::translate("exec_window", "\350\277\233\347\250\213\350\260\203\345\272\246\347\273\223\346\236\234", Q_NULLPTR));
        btn_ret->setText(QApplication::translate("exec_window", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class exec_window: public Ui_exec_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXEC_WINDOW_H
