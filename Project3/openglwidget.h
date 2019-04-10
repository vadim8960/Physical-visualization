#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QTime>
#include <QtMath>
#include <QOpenGLWidget>

#include <QDebug>

#define bias 0.79     // Смещение системы координат
#define g    9.8      // Ускорение свободного падения

// Состояние симуляции
enum {
    ANIMATION,
    DRAW_MAIN,
    SHOW_CHANGE,
    STOP_SIMULATION
};

class OpenglWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenglWidget();

    void initializeGL() override;          // Инициализация окна симуляции
    void paintGL() override;               // Отрисовка окна симуляции

    bool setParams(double m1, double m2, double angle);   // Настройка параметров из GUI
    QString getParams();                                  // Получение текущих параметров симуляции

signals:
    void stop_timer();          // Сигнал остановки таймера

public slots:
    void setStatusPainter(unsigned status);  // Слот настройки состояния симуляции посредством сигнала из MainWindow

private:
    double x0, y0;                   // Начальные координаты начала и конца стержня
    double x, y;                     // Текущие координаты
    double ax, ay;                   // Ускорения начала и конца стержня
    double m1, m2;                   // Коеффициенты трения стены и пола
    double angle;                    // Текущий угол стержня относительно пола
    double t;                        // Текущее время системы

    unsigned status;                 // Текущее состояние системы

    void startAnimation();           // Отрисовка анимации
    void startMain();                // Отрисовка начального экрана
    void startShowChange();          // Отрисовка изменений за некоторое dt
    void stopAnimation();            // Остановка отрисовки

    void draw_grid();                // Отрисовка поверхностей пола и стены
    void clean();                    // Отчистка экрана
    void draw_line();                // Отрисовка стержня

    void change_parameters();        // Изменение параметров системы за некоторое dt
};

#endif // OPENGLWIDGET_H
