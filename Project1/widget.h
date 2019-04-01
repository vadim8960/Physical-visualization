#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QOpenGLWidget>
#include <QDebug>

class Widget : public QOpenGLWidget
{
public:
    Widget(QWidget *parent = nullptr);
    virtual void initializeGL() override;
    virtual void resizeGL(int nWidth, int nHeight) override;
    virtual void paintGL() override;
};

#endif // WIDGET_H
