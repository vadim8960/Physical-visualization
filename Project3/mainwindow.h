#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openglwidget.h"

#include <QTimer>

enum {
    FREEZE,
    CONTINUE,
    WAIT
};

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
    void on_btn_stop_clicked();
    void on_btn_freeze_clicked();
    void start_timer();

private:
    Ui::MainWindow *ui;
    OpenglWidget *simulation;
    QTimer *timer;

    unsigned status_button;

    void show_message(QString msg = "");
    bool check_is_empty();
};

#endif // MAINWINDOW_H
