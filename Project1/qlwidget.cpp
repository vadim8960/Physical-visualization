#include "qlwidget.h"

qlwidget::qlwidget(QWidget *parent)
    : QOpenGLWidget (parent) {  }

void qlwidget::initializeGL() {
    glClearColor(252, 255, 255, 1);
//    qDebug() << "Init";
}

void qlwidget::resizeGL(int nWidth, int nHeight) {
    glViewport(0, 0, nWidth, nHeight); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы
//    qDebug() << "Resize";
}

void qlwidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана
    glMatrixMode(GL_MODELVIEW); // задаем модельно-видовую матрицу
    glLoadIdentity();           // загрузка единичную матрицу
    glColor3i(152, 152, 152);
    glRecti(1, 1, 3, 3);
//    qDebug() << "Paint";
}
