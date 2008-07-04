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

int calculateTextWidth(const std::string& text, const int& padding) {
    int textWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text.c_str());
    textWidth += (2 * padding);
    return textWidth;
}

int calculateTextHeight(const std::string& text, const int& padding) {
    int textHeight = 24;
    textHeight += (2 * padding);
    return textHeight;
}

void drawCenteredText(const std::string& text, const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGB& color) {
    // Calculo ancho del texto.
    int textWidth = calculateTextWidth(text);
    // Calculo alto del texto.
    int textHeight = calculateTextHeight(text);
    // Calculo posicion centrada del texto en x.
    int centeredX = x + ((width - textWidth) / 2);
    // Calculo posicion centrada de texto en y.
    int centeredY = y + (textHeight) + ((height - textHeight) / 2);
    // Dibujo el texto centrado.
    drawText(text, centeredX, centeredY, color);
}

void drawText(const std::string& text, const GLfloat& x, const GLfloat& y, const ColorRGB& color) {
	glColor3f(color.red, color.green, color.blue);
    glRasterPos2f(x, y);
    for (int counter = 0; counter < text.size(); ++ counter) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[counter]);
    }
}

