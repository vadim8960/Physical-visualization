#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Widget* wid = new Widget;

    ui->graphic_layout->addWidget(wid);

    wid->paintGL();
}

MainWindow::~MainWindow()
{
    delete ui;
}
