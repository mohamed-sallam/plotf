/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customPlot;
    QVBoxLayout *verticalLayout_3;
    QLabel *function_label;
    QLineEdit *function_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *x1_label;
    QLabel *x2_label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *x1_lineEdit;
    QLineEdit *x2_lineEdit;
    QPushButton *plot_pushButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(635, 0));

        horizontalLayout->addWidget(customPlot);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        function_label = new QLabel(centralwidget);
        function_label->setObjectName(QStringLiteral("function_label"));
        function_label->setMaximumSize(QSize(136, 16777215));

        verticalLayout_3->addWidget(function_label);

        function_lineEdit = new QLineEdit(centralwidget);
        function_lineEdit->setObjectName(QStringLiteral("function_lineEdit"));
        function_lineEdit->setMaximumSize(QSize(136, 16777215));

        verticalLayout_3->addWidget(function_lineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        x1_label = new QLabel(centralwidget);
        x1_label->setObjectName(QStringLiteral("x1_label"));
        x1_label->setMaximumSize(QSize(136, 16777215));

        horizontalLayout_3->addWidget(x1_label);

        x2_label = new QLabel(centralwidget);
        x2_label->setObjectName(QStringLiteral("x2_label"));
        x2_label->setMaximumSize(QSize(136, 16777215));

        horizontalLayout_3->addWidget(x2_label);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        x1_lineEdit = new QLineEdit(centralwidget);
        x1_lineEdit->setObjectName(QStringLiteral("x1_lineEdit"));
        x1_lineEdit->setMaximumSize(QSize(65, 16777215));

        horizontalLayout_2->addWidget(x1_lineEdit);

        x2_lineEdit = new QLineEdit(centralwidget);
        x2_lineEdit->setObjectName(QStringLiteral("x2_lineEdit"));
        x2_lineEdit->setMaximumSize(QSize(65, 16777215));

        horizontalLayout_2->addWidget(x2_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        plot_pushButton = new QPushButton(centralwidget);
        plot_pushButton->setObjectName(QStringLiteral("plot_pushButton"));
        plot_pushButton->setMaximumSize(QSize(136, 16777215));

        verticalLayout_3->addWidget(plot_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Function Plotter", nullptr));
        function_label->setText(QApplication::translate("MainWindow", "Function in x {f(x)}", nullptr));
        function_lineEdit->setText(QApplication::translate("MainWindow", "x ^ 2", nullptr));
        x1_label->setText(QApplication::translate("MainWindow", "Start (x1)", nullptr));
        x2_label->setText(QApplication::translate("MainWindow", "End (x2)", nullptr));
        x1_lineEdit->setText(QApplication::translate("MainWindow", "-1", nullptr));
        x2_lineEdit->setText(QApplication::translate("MainWindow", "1", nullptr));
        plot_pushButton->setText(QApplication::translate("MainWindow", "Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
