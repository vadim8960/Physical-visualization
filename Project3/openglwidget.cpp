#include "openglwidget.h"

OpenglWidget::OpenglWidget() {
    status = 1;
}

/////////////////////////////////////////////////////
////           Begin public block                ////
/////////////////////////////////////////////////////

void OpenglWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glEnable(GL_SMOOTH);
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
    case 3:
        stopAnimation();
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
        t = 0;
        return true;
    }
    return false;
}

QString OpenglWidget::getParams() {
    QString res = "";
    res += ("time = " + QString::number(t, 'd', 3) + ", ");
    res += ("angle = " + QString::number(qRadiansToDegrees(qAtan(y/x)), 'd', 3) + ", ");
    res += ("vx = " + QString::number(ax * t, 'd', 3) + ", ");
    res += ("vy = " + QString::number(ay * t, 'd', 3));
    qDebug() << res;
    return res;
}

/////////////////////////////////////////////////////
////           Begin slots block                 ////
/////////////////////////////////////////////////////

void OpenglWidget::setStatusPainter(unsigned status) {
    this->status = status;
    if (status == ANIMATION)
        change_parameters();
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

void OpenglWidget::stopAnimation() {
    x = x0;
    y = y0;
    t = 0;
    startShowChange();
}

void OpenglWidget::change_parameters() {
    t += 0.001;
    angle = qAtan(y / x);
    ax = (g * qTan(angle)) / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
    ay = g / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
    x += ((ax * t * t) / 2);
    y -= ((ay * t * t) / 2);
    if (y <= 0) {
        y = 0;
        emit stop_timer();
  }
}
