#ifndef QLWIDGET_H
#define QLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QDebug>

class qlwidget : public QOpenGLWidget
{
public:
    qlwidget(QWidget *parent = nullptr);
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;
};

#endif // QLWIDGET_H
