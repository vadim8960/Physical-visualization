#include "openglwidget.h"

OpenglWidget::OpenglWidget()
{
    status = 1;
    connect(this, &OpenglWidget::startChange, this, &OpenglWidget::changeParameters);
}

/////////////////////////////////////////////////////
////           Begin public block                ////
/////////////////////////////////////////////////////

void OpenglWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glEnable(GL_SMOOTH);
}

void OpenglWidget::resizeGL(int w, int h) {

}

extern void OpenglWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    switch (status) {
    case 0:
        startAnimation();
    break;
    case 1:
        startMain();
    break;
    case 2:
        startShowChange();
    break;
    }
}

bool OpenglWidget::setParams(double m1, double m2, double angle) {
    if (qAtan(0.5/m2 - m1) > angle) {
        this->m1 = m1;
        this->m2 = m2;
        this->angle = angle;
        x = x0 = static_cast <double> (qCos(angle));
        y = y0 = static_cast <double> (qSin(angle));
        return true;
    }
    return false;
}

void OpenglWidget::setStatusPainter(unsigned status) {
    this->status = status;
}

unsigned OpenglWidget::getStatus() {
    return status;
}

void OpenglWidget::changeParameters() {
    qDebug() << "Start change parameters";
    angle = qAtan(y / x);
    double ax = (g * qTan(angle)) / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
    double ay = g / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
    x += (1/2 * ax * t * t);
    y -= (1/2 * ay * t * t);
    qDebug() << x << " " << y << " " << t << " " << ax << " " << ay;
    t += 0.01;
}

/////////////////////////////////////////////////////
////           Begin private block               ////
/////////////////////////////////////////////////////

void OpenglWidget::draw_grid() {
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2d(-0.8, 0.95);
        glVertex2d(-0.8, -0.8);
        glVertex2d(-0.8, -0.8);
        glVertex2d(0.95, -0.8);
        for (double iter_y = -0.8; iter_y < 0.95; iter_y += 0.1) {
            glVertex2d(-0.8, iter_y);
            glVertex2d( -0.9, iter_y - 0.1);
        }
        for (double iter_x = -0.7; iter_x < 0.95; iter_x += 0.1) {
            glVertex2d(iter_x, -0.8);
            glVertex2d(iter_x - 0.1, -0.9);
        }
    glEnd();
}

void OpenglWidget::clean() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenglWidget::draw_line() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(1, 0, 0);
        glVertex2d(x - bias, -bias);
        glVertex2d(-bias, y - bias);
    glEnd();
}

void OpenglWidget::startAnimation() {
    qDebug() << "Start animation";
    startShowChange();
}

void OpenglWidget::startMain() {
    draw_grid();
    update();
}

void OpenglWidget::startShowChange() {
    clean();
    draw_grid();
    draw_line();
    update();
}
