#include "glhelper.h"

void drawFilledRectangle(const GLfloat& x, const GLfloat& y,
    const GLfloat& width, const GLfloat& height, const ColorRGB& color) {
    glColor3f(color.red, color.green, color.blue);
    glRectf(x, y, x + width, y - height);
}

void drawFilledRectangle(const GLfloat& x, const GLfloat& y,
    const GLfloat& width, const GLfloat& height, const ColorRGBA& color) {
    glColor4f(color.red, color.green, color.blue, color.alpha);
    glRectf(x, y, x + width, y - height);
}

