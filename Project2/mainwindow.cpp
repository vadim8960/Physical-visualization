#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(831, 449);
    simulation = new OpenglWidget;
    ui->graphic_layout->addWidget(simulation);
    simulation->setFixedSize(380, 380);
    simulation->setStatusPainter(DRAW_MAIN);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::on_btn_show_clicked() {
    bool res = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                     ui->lineEdit_m1->text().toDouble(),
                                     qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
    ui->lbl_error->setText(QString( (res) ? "TRUE" : "FALSE" ));
    simulation->setStatusPainter(SHOW_CHANGE);
    simulation->update();
}
