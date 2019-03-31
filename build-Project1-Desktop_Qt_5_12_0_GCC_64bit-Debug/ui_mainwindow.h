/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QLineEdit *libeEdit_m1;
    QLineEdit *lineEdit_m2;
    QLineEdit *lineEdit_mass;
    QLineEdit *lineEdit_angle;
    QLabel *lbl_m1;
    QLabel *lbl_m2;
    QLabel *lbl_mass;
    QLabel *lbl_angle;
    QPushButton *btn_freeze;
    QOpenGLWidget *gr_window;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(871, 510);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(550, 240, 111, 51));
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(700, 240, 111, 51));
        libeEdit_m1 = new QLineEdit(centralWidget);
        libeEdit_m1->setObjectName(QString::fromUtf8("libeEdit_m1"));
        libeEdit_m1->setGeometry(QRect(690, 30, 113, 25));
        lineEdit_m2 = new QLineEdit(centralWidget);
        lineEdit_m2->setObjectName(QString::fromUtf8("lineEdit_m2"));
        lineEdit_m2->setGeometry(QRect(690, 70, 113, 25));
        lineEdit_mass = new QLineEdit(centralWidget);
        lineEdit_mass->setObjectName(QString::fromUtf8("lineEdit_mass"));
        lineEdit_mass->setGeometry(QRect(690, 110, 113, 25));
        lineEdit_angle = new QLineEdit(centralWidget);
        lineEdit_angle->setObjectName(QString::fromUtf8("lineEdit_angle"));
        lineEdit_angle->setGeometry(QRect(690, 150, 113, 25));
        lbl_m1 = new QLabel(centralWidget);
        lbl_m1->setObjectName(QString::fromUtf8("lbl_m1"));
        lbl_m1->setGeometry(QRect(610, 30, 67, 17));
        lbl_m2 = new QLabel(centralWidget);
        lbl_m2->setObjectName(QString::fromUtf8("lbl_m2"));
        lbl_m2->setGeometry(QRect(610, 70, 67, 17));
        lbl_mass = new QLabel(centralWidget);
        lbl_mass->setObjectName(QString::fromUtf8("lbl_mass"));
        lbl_mass->setGeometry(QRect(610, 110, 67, 17));
        lbl_angle = new QLabel(centralWidget);
        lbl_angle->setObjectName(QString::fromUtf8("lbl_angle"));
        lbl_angle->setGeometry(QRect(610, 150, 67, 17));
        btn_freeze = new QPushButton(centralWidget);
        btn_freeze->setObjectName(QString::fromUtf8("btn_freeze"));
        btn_freeze->setGeometry(QRect(630, 310, 111, 51));
        gr_window = new QOpenGLWidget(centralWidget);
        gr_window->setObjectName(QString::fromUtf8("gr_window"));
        gr_window->setEnabled(true);
        gr_window->setGeometry(QRect(20, 30, 481, 401));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btn_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        lbl_m1->setText(QApplication::translate("MainWindow", "m1", nullptr));
        lbl_m2->setText(QApplication::translate("MainWindow", "m2", nullptr));
        lbl_mass->setText(QApplication::translate("MainWindow", "mass", nullptr));
        lbl_angle->setText(QApplication::translate("MainWindow", "angle", nullptr));
        btn_freeze->setText(QApplication::translate("MainWindow", "Freeze", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
