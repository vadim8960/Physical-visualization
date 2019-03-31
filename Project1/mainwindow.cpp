#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Widget wid(ui->gr_window);
    wid.initializeGL();
    wid.resizeGL(100, 100);
    wid.paintGL();
}

MainWindow::~MainWindow()
{
    delete ui;
}
