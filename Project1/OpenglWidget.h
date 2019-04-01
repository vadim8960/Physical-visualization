#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QOpenGLWidget>
#include <QDebug>
#include <QtMath>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

#define bias 0.79
#define g    9.8

class OpenglWidget : public QOpenGLWidget
{
public:
    OpenglWidget(QWidget *parent = nullptr);

    bool setParams(double m1, double m2, double angle);
    void startAnimation();

    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

private:
    double x0, y0;
    double m1, m2;
    double angle;
    double x, y;
    double x_l, y_l;

    bool check_enter_data(double m1, double m2, double angle);
    void delay(int millisecondsToWait);

    void draw_grid();
    void clean();
    void draw_line(bool status);
};

#endif // WIDGET_H
