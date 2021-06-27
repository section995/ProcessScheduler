/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *table_input;
    QComboBox *comboBox;
    QPushButton *btn_exec;
    QLineEdit *le_jobcount;
    QPushButton *btn_ok;
    QPushButton *btn_import;
    QPushButton *btn_clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(351, 549);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        table_input = new QTableWidget(centralwidget);
        table_input->setObjectName(QStringLiteral("table_input"));
        table_input->setGeometry(QRect(20, 40, 311, 421));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 111, 22));
        btn_exec = new QPushButton(centralwidget);
        btn_exec->setObjectName(QStringLiteral("btn_exec"));
        btn_exec->setGeometry(QRect(130, 470, 91, 31));
        le_jobcount = new QLineEdit(centralwidget);
        le_jobcount->setObjectName(QStringLiteral("le_jobcount"));
        le_jobcount->setGeometry(QRect(140, 10, 141, 20));
        btn_ok = new QPushButton(centralwidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(290, 10, 41, 21));
        btn_import = new QPushButton(centralwidget);
        btn_import->setObjectName(QStringLiteral("btn_import"));
        btn_import->setGeometry(QRect(20, 470, 91, 31));
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setGeometry(QRect(240, 470, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 351, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\273\347\252\227\345\217\243", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\260\203\345\272\246\347\256\227\346\263\225", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FCFS", Q_NULLPTR)
         << QApplication::translate("MainWindow", "RR", Q_NULLPTR)
         << QApplication::translate("MainWindow", "SJF", Q_NULLPTR)
         << QApplication::translate("MainWindow", "HRN", Q_NULLPTR)
        );
        btn_exec->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\247\350\241\214", Q_NULLPTR));
        le_jobcount->setInputMask(QString());
        le_jobcount->setText(QString());
        le_jobcount->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\350\260\203\345\272\246\347\232\204\350\277\233\347\250\213\346\225\260\351\207\217", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        btn_import->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245data.txt", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\276\223\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
