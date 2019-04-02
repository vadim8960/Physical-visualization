#include "openglwidget.h"

OpenglWidget::OpenglWidget(QWidget *parent)
    : QOpenGLWidget (parent) { }

/////////////////////////////////////////////////////
////           Begin public block                ////
/////////////////////////////////////////////////////

void OpenglWidget::initializeGL() {

}

void OpenglWidget::resizeGL(int w, int h) {

}

void OpenglWidget::paintGL() {

}

bool OpenglWidget::setParams(double m1, double m2, double angle) {

}

void OpenglWidget::setStatusPainter(unsigned status) {

}

unsigned OpenglWidget::getStatus() {

}

void OpenglWidget::startAnimation() {

}

void OpenglWidget::startMain() {

}

void OpenglWidget::startShowChange() {

}

/////////////////////////////////////////////////////
////           Begin private block               ////
/////////////////////////////////////////////////////

void OpenglWidget::draw_grid() {

}

void OpenglWidget::clean() {

}

void OpenglWidget::draw_line(bool status) {

}
