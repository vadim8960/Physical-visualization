#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(764, 486);
    simulation = new OpenglWidget;
    timer = new QTimer(this);
    timer->setSingleShot(false);
    timer->setInterval(10);
    simulation->setFixedSize(380, 380);
    ui->grlayout->addWidget(simulation);
    simulation->setStatusPainter(DRAW_MAIN);
    connect(simulation, &OpenglWidget::stop_timer,
            timer, &QTimer::stop);
    connect(timer, &QTimer::timeout,
            this, &MainWindow::start_timer);
    connect(this, &MainWindow::status,
            simulation, &OpenglWidget::setStatusPainter);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
    delete timer;
}

/////////////////////////////////////////////////////
////           Begin private block               ////
/////////////////////////////////////////////////////

void MainWindow::show_message(QString msg) {
    ui->lbl_error->setText(msg);
}

bool MainWindow::check_is_empty() {
    return ui->lineEdit_m1->text().isEmpty() ||
           ui->lineEdit_m2->text().isEmpty() ||
           ui->lineEdit_angle->text().isEmpty();
}

/////////////////////////////////////////////////////
////           Begin slots block                 ////
/////////////////////////////////////////////////////

void MainWindow::on_btn_show_clicked() {
    if (check_is_empty()) {
        show_message(QString("Please, enter all variable"));
    } else {
        bool res = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                         ui->lineEdit_m1->text().toDouble(),
                                         qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
        show_message(QString(""));
        if (res)
            simulation->setStatusPainter(SHOW_CHANGE);
        else
            show_message(QString("Very big angle for this m1 and m2"));
    }
}

void MainWindow::on_btn_start_clicked() {
    if (check_is_empty()) {
        show_message(QString("Please, enter all variable"));
    } else {
        bool res = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                         ui->lineEdit_m1->text().toDouble(),
                                         qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
        show_message(QString(""));
        if (res) {
            simulation->setStatusPainter(ANIMATION);
            timer->start();
        } else
            show_message(QString("Very big angle for this m1 and m2"));
    }
}

void MainWindow::start_timer() {
    emit status(ANIMATION);
}
