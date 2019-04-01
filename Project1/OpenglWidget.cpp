#include "OpenglWidget.h"

OpenglWidget::OpenglWidget(QWidget *parent)
    : QOpenGLWidget (parent) {  }

void OpenglWidget::initializeGL()
{
    glClearColor(255, 255, 255, 1);
}

void OpenglWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void OpenglWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    x = -0.5;
    y = -0.5;

    glColor3i(1, 0, 0);
    glLineWidth(2.5);

    glBegin(GL_LINES);
        glVertex2d(-1, 0.5);
        glVertex2d(1, 0.5);
    glEnd();
//    glBegin(GL_LINES);
//      glVertex2f(0.5f, 0.5f);
//      glVertex2f(-0.5f, 0.5f);
//      glVertex2f(-0.5f, -0.5f);
//      glVertex2f(0.5f, -0.5f);
//    glEnd();
}

bool OpenglWidget::check_enter_data(double m1, double m2, double angle) {
    return qRadiansToDegrees(atan(0.5/m2 - m1)) > angle;
}

bool OpenglWidget::setParams(double m1, double m2, double angle) {
    if (check_enter_data(m1, m2, angle)) {
        this->m1 = m1;
        this->m2 = m2;
        this->angle = angle;
        x = x0 = qCos(angle);
        y = y0 = qSin(angle);
        return true;
    }
    return false;
}
