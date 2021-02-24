#include "glwidget.h"
#include <math.h>

#include <unistd.h>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}
void GLWidget::initializeGL(){
    glClearColor(0.2, 0.2, 0.2, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);
}








void GLWidget::paintGL(){


    paintFract(count);
}


void GLWidget::paintFract(int count){

    double dots[6] = {0.0,  1.0,
                      0.87, -0.5,
                      -0.87, -0.5};

    glPushMatrix();

    for (int i = 0; i < count; i++){
        glRotated(5.0, 0.0, 0.0, 0.1);

        //        glPointSize(3);
        //        glBegin(GL_POINTS);
        //            glColor3f(1, 1, 0);
        //            glVertex2d(dots[0],  dots[1]);
        //            glVertex2d(dots[2], dots[3]);
        //            glVertex2d(dots[4], dots[5]);
        //       glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(1, 0, 0);
            glVertex2d(dots[0],  dots[1]);
            glVertex2d(dots[2], dots[3]);
            glVertex2d(dots[4], dots[5]);
        glEnd();

        if (dots[1] >0.0 )dots[1] -= sqrt(pow(0.01, 2) + pow(0.01*(50.0/87.0), 2));

        if (dots[2] > 0.0)dots[2] -= 0.01;
        if (dots[3] < 0.0)dots[3] += 0.01*(50.0/87.0);

        if (dots[4] < 0.0)dots[4] += 0.01;
        if (dots[5] < 0.0)dots[5] += 0.01*(50.0/87.0);
    }

    glPopMatrix();

}

void GLWidget::resizeGL(int w, int h){
//    glViewport(0,0,w,h);
}
