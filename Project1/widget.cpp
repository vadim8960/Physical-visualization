#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget (parent) {  }

void Widget::initializeGL()
{
    glClearColor(252, 255, 255, 1);
    qDebug() << "Init";
}

void Widget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nWidth, nHeight); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы
    qDebug() << "Resize";
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана
    glMatrixMode(GL_MODELVIEW); // задаем модельно-видовую матрицу
    glLoadIdentity();           // загрузка единичную матрицу
    glColor3i(152, 152, 152);
    glRecti(1, 1, 3, 3);
    qDebug() << "Paint";

}
