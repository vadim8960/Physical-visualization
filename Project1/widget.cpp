#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget (parent)
{
    resize(300,300); // задаем размеры окна
}

void Widget::initializeGL()
{
//    glClearColor(QColor(255, 255, 255));
    glClearColor(252, 255, 255, 1);
    qDebug() << "Init";
}

void Widget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nHeight, nHeight); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы
    qDebug() << "Resize";
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана
    glMatrixMode(GL_MODELVIEW); // задаем модельно-видовую матрицу
    glLoadIdentity();           // загрузка единичную матрицу
//    glColor(QColor(0, 0, 0));
    glColor3b(152, 152, 152);
    glBegin(GL_QUADS); // говорим, что рисовать будем прямоугольник
       // задаем вершины многоугольника
       glVertex3f(0.5, 0.5, 0.5);
       glVertex3f(-0.5, 0.5, 0.5);
       glVertex3f(-0.5, -0.5, 0.5);
       glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    qDebug() << "Paint";

}
