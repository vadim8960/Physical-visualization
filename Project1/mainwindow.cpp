#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    simulation = new OpenglWidget;

    ui->graphic_layout->addWidget(simulation);

    simulation->resizeGL(10, 10);

    simulation->paintGL();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::on_btn_start_clicked()
{
    simulation->setParams(ui->lbl_m1->text().toDouble(),
                          ui->lbl_m2->text().toDouble(),
                          ui->lbl_angle->text().toDouble());

}
