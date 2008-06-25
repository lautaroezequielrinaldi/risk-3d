#include "gldrawhelper.h"

void GLDrawHelper::drawRectangle(const GLint& left, const GLint& right, const GLint& top, const GLint& bottom,
    Color& color) {
    glBegin(GL_LINE_STRIP);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(left, bottom);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(left, top);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(right, top);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(right, bottom);
    glEnd();
}

void GLDrawHelper::drawFillRectangle(const GLint& left, const GLint& right, const GLint& top, const GLint& bottom,
	Color& color) {
    glBegin(GL_QUADS);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(left, bottom);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(left, top);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(right, top);
        glColor3f(color.getRed(), color.getGreen(), color.getBlue());
        glVertex2i(right, bottom);
    glEnd();
}

void GLDrawHelper::drawCenteredText(const std::string& text, Dimension& dimension, Color& color) {
	// Calculo ancho del texto.
	int textWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text.c_str());
	// Calculo alto del texto.
	int textHeight = 24;
	// Calculo posicion centrada del texto en x.
	int centeredX = dimension.getX() + ((dimension.getWidth() - textWidth) / 2);
	// Calculo posicion centrada de texto en y.
	int centeredY = dimension.getY() + (textHeight / 2) + ((dimension.getHeight() - textHeight) / 2);
	// Draws the text in the centeredX and centeredY position.
	GLDrawHelper::drawText(text, centeredX, centeredY, color);
}

void GLDrawHelper::drawText(const std::string& text, const GLint& x, const GLint& y, Color& color) {
    glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	glRasterPos2f(x, y);
	for (int counter = 0; counter < text.size(); ++ counter) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[counter]);
	}
}

