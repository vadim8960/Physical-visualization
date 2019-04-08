#include "mainwind.h"
#include "ui_mainwind.h"

#include <QAction>
#include <QListView>

MainWind::MainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWind)
{
    ui->setupUi(this);
    QAction* act = new QAction;
    act->setText("Hello");
    ui->listView->addAction(act);
    ui->listView->update();
}

MainWind::~MainWind()
{
    delete ui;
}
