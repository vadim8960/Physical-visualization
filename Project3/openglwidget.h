#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QGLWidget>
#include <QDebug>
#include <QtMath>
#include <QTime>
#include <QObject>

#include <QtConcurrent>
#include <QFuture>
#include <QThreadPool>

#define bias 0.79
#define g    9.8

enum {
    ANIMATION,
    DRAW_MAIN,
    SHOW_CHANGE
};

class OpenglWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenglWidget();

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    bool setParams(double m1, double m2, double angle);

    unsigned getStatus();

signals:
    void startChange();
    void stop_timer();

public slots:
    void changeParameters();
    void setStatusPainter(unsigned status);

private:
    double x0, y0;
    double x, y;
    double m1, m2;
    double angle;
    double t;

    unsigned status;

    void startAnimation();
    void startMain();
    void startShowChange();

    void draw_grid();
    void clean();
    void draw_line();

    void delay(int msec);
};

#endif // OPENGLWIDGET_H