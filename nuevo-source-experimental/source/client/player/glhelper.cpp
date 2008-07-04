#include "glhelper.h"

void drawFilledRectangle(const GLfloat& width, const GLfloat& height, const ColorRGB& color) {
    glColor3f(color.red, color.green, color.blue);
    glBegin(GL_QUADS);
        glVertex2d(0,height/2);
        glVertex2d(0,-height/2);
        glVertex2d(width,-height/2);
        glVertex2d(width,height/2);
    glEnd();
}

void drawFilledRectangle(const GLfloat& width, const GLfloat& height, const ColorRGBA& color) {
    glColor4f(color.red, color.green, color.blue, color.alpha);
    glColor3f(color.red, color.green, color.blue);
    glBegin(GL_QUADS);
        glVertex2d(0,height/2);
        glVertex2d(0,-height/2);
        glVertex2d(width,-height/2);
        glVertex2d(width,height/2);
    glEnd();
}

