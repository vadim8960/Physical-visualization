#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widget.h"
#include "qlwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qlwidget ww(ui->gr_window);
    ww.paintGL();
    ww.show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
