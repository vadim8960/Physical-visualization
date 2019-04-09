#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openglwidget.h"

#include <QTimer>

// Состояния кнопки Freeze
enum {
    FREEZE,
    CONTINUE,
    WAIT
};

// Объявление пространста имен для икслючения корреляции имен
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Конструктор
    ~MainWindow();                                  // Деструктор

signals:
    void status(unsigned st);       // Сигнал настройки состояния виджета OpenglWidget

private slots:
    void on_btn_show_clicked();     // Слот нажатия кнопки Show
    void on_btn_start_clicked();    // Слот нажатия кнопки Start
    void on_btn_stop_clicked();     // Слот нажатия кнопки Stop
    void on_btn_freeze_clicked();   // Слот нажатия кнопки Freeze
    void start_timer();             // Слот запуска таймера для начала анимации
    void show_params();             // Слот для вывода текущих параметров системы

private:
    Ui::MainWindow *ui;             // Основное окно
    OpenglWidget *simulation;       // Виджет OpenglWidget
    QTimer *timer;                  // Таймер для обновления виджета OpenglWidget

    unsigned status_button;         // Текущее состояние кнопки Freeze

    void show_message(QString msg = "");   // Вывод ошибки
    bool check_is_empty();                 // Проверка на корректность введенных данных
};

#endif // MAINWINDOW_H
