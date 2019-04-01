#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OpenglWidget.h"

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
    void on_btn_start_clicked();

private:
    Ui::MainWindow *ui;
    OpenglWidget *simulation;
};

#endif // MAINWINDOW_H
