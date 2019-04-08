#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QTime>
#include <QtMath>
#include <QOpenGLWidget>

#include <QDebug>

#define bias 0.79
#define g    9.8

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

    void initializeGL() override;
    void paintGL() override;

    bool setParams(double m1, double m2, double angle);
    QString getParams();

signals:
    void stop_timer();

public slots:
    void setStatusPainter(unsigned status);

private:
    double x0, y0;
    double x, y;
    double ax, ay;
    double m1, m2;
    double angle;
    double t;

    unsigned status;

    void startAnimation();
    void startMain();
    void startShowChange();
    void stopAnimation();

    void draw_grid();
    void clean();
    void draw_line();

    void change_parameters();
};

#endif // OPENGLWIDGET_H
