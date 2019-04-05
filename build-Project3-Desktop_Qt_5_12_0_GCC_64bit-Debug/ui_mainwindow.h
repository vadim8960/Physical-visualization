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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_show;
    QLabel *lbl_m1;
    QPushButton *btn_freeze;
    QLabel *lbl_angle;
    QLineEdit *lineEdit_mass;
    QLabel *lbl_m2;
    QLabel *lbl_error;
    QLineEdit *lineEdit_m1;
    QPushButton *btn_start;
    QLabel *lbl_mass;
    QLineEdit *lineEdit_m2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *grlayout;
    QPushButton *btn_stop;
    QLineEdit *lineEdit_angle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(762, 486);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_show = new QPushButton(centralWidget);
        btn_show->setObjectName(QString::fromUtf8("btn_show"));
        btn_show->setGeometry(QRect(480, 330, 111, 51));
        lbl_m1 = new QLabel(centralWidget);
        lbl_m1->setObjectName(QString::fromUtf8("lbl_m1"));
        lbl_m1->setGeometry(QRect(500, 50, 67, 17));
        btn_freeze = new QPushButton(centralWidget);
        btn_freeze->setObjectName(QString::fromUtf8("btn_freeze"));
        btn_freeze->setGeometry(QRect(630, 330, 111, 51));
        lbl_angle = new QLabel(centralWidget);
        lbl_angle->setObjectName(QString::fromUtf8("lbl_angle"));
        lbl_angle->setGeometry(QRect(500, 170, 67, 17));
        lineEdit_mass = new QLineEdit(centralWidget);
        lineEdit_mass->setObjectName(QString::fromUtf8("lineEdit_mass"));
        lineEdit_mass->setGeometry(QRect(580, 130, 113, 25));
        lbl_m2 = new QLabel(centralWidget);
        lbl_m2->setObjectName(QString::fromUtf8("lbl_m2"));
        lbl_m2->setGeometry(QRect(500, 90, 67, 17));
        lbl_error = new QLabel(centralWidget);
        lbl_error->setObjectName(QString::fromUtf8("lbl_error"));
        lbl_error->setGeometry(QRect(480, 220, 261, 20));
        lbl_error->setStyleSheet(QString::fromUtf8(""));
        lineEdit_m1 = new QLineEdit(centralWidget);
        lineEdit_m1->setObjectName(QString::fromUtf8("lineEdit_m1"));
        lineEdit_m1->setGeometry(QRect(580, 50, 113, 25));
        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(480, 260, 111, 51));
        lbl_mass = new QLabel(centralWidget);
        lbl_mass->setObjectName(QString::fromUtf8("lbl_mass"));
        lbl_mass->setGeometry(QRect(500, 130, 67, 17));
        lineEdit_m2 = new QLineEdit(centralWidget);
        lineEdit_m2->setObjectName(QString::fromUtf8("lineEdit_m2"));
        lineEdit_m2->setGeometry(QRect(580, 90, 113, 25));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 441, 391));
        grlayout = new QVBoxLayout(verticalLayoutWidget);
        grlayout->setSpacing(6);
        grlayout->setContentsMargins(11, 11, 11, 11);
        grlayout->setObjectName(QString::fromUtf8("grlayout"));
        grlayout->setContentsMargins(0, 0, 0, 0);
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(630, 260, 111, 51));
        lineEdit_angle = new QLineEdit(centralWidget);
        lineEdit_angle->setObjectName(QString::fromUtf8("lineEdit_angle"));
        lineEdit_angle->setGeometry(QRect(580, 170, 113, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 762, 22));
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
        btn_show->setText(QApplication::translate("MainWindow", "Show", nullptr));
        lbl_m1->setText(QApplication::translate("MainWindow", "m1", nullptr));
        btn_freeze->setText(QApplication::translate("MainWindow", "Freeze", nullptr));
        lbl_angle->setText(QApplication::translate("MainWindow", "angle", nullptr));
        lbl_m2->setText(QApplication::translate("MainWindow", "m2", nullptr));
        lbl_error->setText(QString());
        btn_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        lbl_mass->setText(QApplication::translate("MainWindow", "mass", nullptr));
        btn_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
