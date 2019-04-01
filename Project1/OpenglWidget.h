#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QOpenGLWidget>
#include <QDebug>
#include <QtMath>

#define bias 0.5

class OpenglWidget : public QOpenGLWidget
{
public:
    OpenglWidget(QWidget *parent = nullptr);

    bool setParams(double m1, double m2, double angle);

    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

private:
    double x0, y0;
    double m1, m2;
    double angle;
    double x, y;

    bool check_enter_data(double m1, double m2, double angle);

    void draw_grid();
    void clean();
    void draw_line();
};

#endif // WIDGET_H
