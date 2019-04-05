#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton;
    button->setText(QString("Button"));

    QLabel *label = new QLabel;
    label->setText(QString("Text"));

    QLineEdit *lineEdit = new QLineEdit;

    ui->verticalLayout->addWidget(lineEdit);
    ui->verticalLayout->addWidget(button);
    ui->verticalLayout->addWidget(label);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//slot
void MainWindow::showMessage() {
    QMessageBox::information(this, ".", ".");
}
