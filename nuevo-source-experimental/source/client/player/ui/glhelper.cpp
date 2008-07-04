#include "glhelper.h"

void drawFilledRectangle(const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGB& color) {
    glColor3f(color.red, color.green, color.blue);
/*    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y - height);
        glVertex2f(x, y - height);
    glEnd();*/
    glRectf(x, y, x + width, y + height);
}


void drawFilledRectangle(const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGBA& color) {
    glColor4f(color.red, color.green, color.blue, color.alpha);
/*    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y - height);
        glVertex2f(x, y - height);
    glEnd();*/
    glRectf(x, y, x + width, y + height);
}

