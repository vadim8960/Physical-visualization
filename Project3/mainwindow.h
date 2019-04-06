#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openglwidget.h"

#include <QThread>
#include <QtMath>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void status(unsigned st);

private slots:
    void on_btn_show_clicked();

    void on_btn_start_clicked();

    void start_timer();

private:
    Ui::MainWindow *ui;
    OpenglWidget *simulation;
    QTimer *timer;

    void show_message(bool res, QString msg = "");
    bool check_is_empty();
};

#endif // MAINWINDOW_H
