#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    simulation = new OpenglWidget;

    ui->graphic_layout->addWidget(simulation);
    simulation->setStatusPainter(DRAW_MAIN);
//    simulation->paintGL();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::print_error() {
    ui->lbl_error->setText(QString("error"));
}

void MainWindow::print_true() {
    ui->lbl_error->setText(QString("true"));
}

void MainWindow::on_btn_start_clicked()
{
    simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                          ui->lineEdit_m2->text().toDouble(),
                          qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
    simulation->setStatusPainter(ANIMATION);
    simulation->paintGL();

}

void MainWindow::on_btn_show_clicked()
{
    bool st = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                    ui->lineEdit_m2->text().toDouble(),
                                    qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
    if (!st)
        print_error();
    else {
        print_true();
        simulation->setStatusPainter(SHOW_CHANGE);
        simulation->paintGL();
    }
}
