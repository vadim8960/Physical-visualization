#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(831, 449);
    simualtion = new OpenglWidget;
    ui->graphic_layout->addWidget(simualtion);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simualtion;
}
