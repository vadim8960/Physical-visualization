#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QOpenGLWidget>
#include <QDebug>

class Widget : public QOpenGLWidget
{
public:
    Widget(QWidget *parent = nullptr);
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;
};

#endif // WIDGET_H
