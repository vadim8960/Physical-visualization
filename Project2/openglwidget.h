#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QGLWidget>
#include <QDebug>
#include <QtMath>

#define bias 0.79
#define g    9.8

enum {
    ANIMATION,
    DRAW_MAIN,
    SHOW_CHANGE
};

class OpenglWidget : public QOpenGLWidget
{
public:
    OpenglWidget(QWidget *parent = nullptr);

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    bool setParams(double m1, double m2, double angle);

    void setStatusPainter(unsigned status);
    unsigned getStatus();

    void startAnimation();
    void startMain();
    void startShowChange();

private:
    double x0, y0;
    double x, y;
    double m1, m2;
    double angle;

    unsigned status;

    void draw_grid();
    void clean();
    void draw_line();
};

#endif // OPENGLWIDGET_H
