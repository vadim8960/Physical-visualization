#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget (parent)
{
    resize(300,300); // задаем размеры окна
}

void Widget::initializeGL()
{
    //qglClearColor(Qt::white); // заполняем экран белым цветом
    //glClearColor(Qt::white);
    glClearColor(225, 225, 225, 1);
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
    glShadeModel(GL_FLAT); // убираем режим сглаживания цветов
    glEnable(GL_CULL_FACE); // говорим, что будем строить только внешние поверхности
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); // фигуры будут закрашены с обеих сторон
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
    glBegin(GL_QUADS); // говорим, что рисовать будем прямоугольник
       // задаем вершины многоугольника
       glVertex3f(0.5, 0.5, 0.5);
       glVertex3f(-0.5, 0.5, 0.5);
       glVertex3f(-0.5, -0.5, 0.5);
       glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    qDebug() << "Paint";
}
