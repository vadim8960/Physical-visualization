#include "OpenglWidget.h"

OpenglWidget::OpenglWidget(QWidget *parent)
    : QOpenGLWidget (parent) {  }

void OpenglWidget::initializeGL() {
    glClearColor(255, 255, 255, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenglWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void OpenglWidget::paintGL() {
    startAnimation();
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenglWidget::draw_line(bool status) {
    double tmp_x = (status) ? x : x_l;
    double tmp_y = (status) ? y : y_l;
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3d(status, 0, 0);
        glVertex2d(tmp_x - bias, -bias);
        glVertex2d(-bias, tmp_y - bias);
    glEnd();
}

void OpenglWidget::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void OpenglWidget::startAnimation() {
    clean();
    draw_grid();
    double t = 0;
    while (y > -bias) {
        draw_line(true);
        angle = qAtan(y / x);
        double ax = (g * qTan(angle)) / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
        double ay = g / ( (1 + m1 * m2) * (1 + m1 * qTan(angle)) );
        x = x0 + 1/2 * ax * t * t;
        y = y0 + 1/2 * ay * t * t;
        delay(10);
        t += 0.1;
        draw_line(false);
        x_l = x;
        y_l = y;
    }
}
