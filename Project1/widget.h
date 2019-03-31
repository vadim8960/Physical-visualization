#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>

#include <QDebug>

class Widget : public QOpenGLWidget
{
public:
    Widget(QWidget *parent);
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
};

#endif // WIDGET_H
