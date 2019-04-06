#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(764, 486);
    simulation = new OpenglWidget;
    timer = new QTimer;
    timer->setInterval(100);
    simulation->setFixedSize(380, 380);
    ui->grlayout->addWidget(simulation);
    simulation->setStatusPainter(DRAW_MAIN);
    connect(simulation, &OpenglWidget::stop_timer, timer, &QTimer::stop);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simulation;
}

void MainWindow::show_message(bool res, QString msg) {
    if (res) {
        ui->lbl_error->clear();
    } else {
        ui->lbl_error->setText(msg);
    }
}

bool MainWindow::check_is_empty() {
    return ui->lineEdit_m1->text().isEmpty() ||
           ui->lineEdit_m2->text().isEmpty() ||
           ui->lineEdit_angle->text().isEmpty();
}

void MainWindow::on_btn_show_clicked() {
    if (check_is_empty()) {
        show_message(false, QString("Please, enter all variable"));
    } else {
        bool res = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                         ui->lineEdit_m1->text().toDouble(),
                                         qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
        show_message(res);
        if (res)
            simulation->setStatusPainter(SHOW_CHANGE);
        else
            show_message(res, QString("Very big angle for this m1 and m2"));
    }
}

void MainWindow::start_timer() {
    emit status(ANIMATION);
}

void MainWindow::on_btn_start_clicked() {
    if (check_is_empty()) {
        show_message(false, QString("Please, enter all variable"));
    } else {
        bool res = simulation->setParams(ui->lineEdit_m1->text().toDouble(),
                                         ui->lineEdit_m1->text().toDouble(),
                                         qDegreesToRadians(ui->lineEdit_angle->text().toDouble()));
        show_message(res);
        if (res) {
            simulation->setStatusPainter(ANIMATION);
            timer->start(10);
            connect(timer, &QTimer::timeout,
                    this, &MainWindow::start_timer);
            connect(this, &MainWindow::status,
                    simulation, &OpenglWidget::setStatusPainter);
        } else
            show_message(res, QString("Very big angle for this m1 and m2"));
    }
}
