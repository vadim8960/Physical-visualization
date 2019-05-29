#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status_button = WAIT;
    this->setFixedSize(719, 511);
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

    connect(timer, &QTimer::timeout,
            this, &MainWindow::show_params);

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
    QString s1 = ui->lineEdit_m1->text();
    QString s2 = ui->lineEdit_m2->text();
    QString s3 = ui->lineEdit_angle->text();
    for (unsigned iter = 0; iter < s1.size(); ++iter) {
        if (!(48 <= s1[iter] && s1[iter] <= 57) && s1[iter] != 46) {
            show_message(QString("Please, enter a value without chars"));
            return true;
        }
    }
    for (unsigned iter = 0; iter < s2.size(); ++iter) {
        if (!(48 <= s2[iter] && s2[iter] <= 57) && s2[iter] != 46) {
            show_message(QString("Please, enter a value without chars"));
            return true;
        }
    }
    for (unsigned iter = 0; iter < s3.size(); ++iter) {
        if (!(48 <= s3[iter] && s3[iter] <= 57) && s3[iter] != 46) {
            show_message(QString("Please, enter a value without chars"));
            return true;
        }
    }
    qDebug() << "Fick";
    if (ui->lineEdit_m1->text().isEmpty() ||
        ui->lineEdit_m2->text().isEmpty() ||
        ui->lineEdit_angle->text().isEmpty())
    {
        show_message(QString("Please, enter all variable"));
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////
////           Begin slots block                 ////
/////////////////////////////////////////////////////

void MainWindow::on_btn_show_clicked() {
    if (check_is_empty()) {

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

void MainWindow::show_params() {
    ui->lbl_params->setText(simulation->getParams());
}

void MainWindow::on_btn_stop_clicked() {
    simulation->setStatusPainter(STOP_SIMULATION);
    timer->stop();
}

void MainWindow::on_btn_freeze_clicked() {
    switch (status_button) {
    case FREEZE:
        ui->btn_freeze->setText(QString("Freeze"));
        status_button = CONTINUE;
        timer->start();
    break;
    case WAIT:
        status_button = CONTINUE;
    [[clang::fallthrough]];
    case CONTINUE:
        ui->btn_freeze->setText(QString("Continue"));
        timer->stop();
        status_button = FREEZE;
    break;
    }
}
