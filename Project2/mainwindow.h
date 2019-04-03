#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openglwidget.h"

#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_show_clicked();

    void on_btn_start_clicked();

private:
    Ui::MainWindow *ui;
    OpenglWidget *simulation;

    void show_message(bool res, QString msg = "");
    bool check_is_empty();
};

#endif // MAINWINDOW_H
