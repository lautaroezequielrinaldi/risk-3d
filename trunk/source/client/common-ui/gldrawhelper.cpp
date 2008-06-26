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

void GLDrawHelper::drawFilledRectangle(const GLint& left, const GLint& right, const GLint& top, const GLint& bottom,
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

int GLDrawHelper::calculateTextWidth(const std::string& text, const int& padding) {
	int textWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) text.c_str());
	textWidth += (2 * padding);
	return textWidth;
}

int GLDrawHelper::calculateTextHeight(const std::string& text, const int& padding) {
	int textHeight = 24;
	textHeight += (2 * padding);
	return textHeight;
}

void GLDrawHelper::drawCenteredText(const std::string& text, Dimension& dimension, Color& color) {
	// Calculo ancho del texto.
	int textWidth = GLDrawHelper::calculateTextWidth(text);
	// Calculo alto del texto.
	int textHeight = GLDrawHelper::calculateTextHeight(text);
	// Calculo posicion centrada del texto en x.
	int centeredX = dimension.getX() + ((dimension.getWidth() - textWidth) / 2);
	// Calculo posicion centrada de texto en y.
	int centeredY = dimension.getY() + (textHeight) + ((dimension.getHeight() - textHeight) / 2);
	// Dibujo el texto centrado.
	GLDrawHelper::drawText(text, centeredX, centeredY, color);
}

void GLDrawHelper::drawText(const std::string& text, const GLint& x, const GLint& y, Color& color) {
    glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	glRasterPos2f(x, y);
	for (int counter = 0; counter < text.size(); ++ counter) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[counter]);
	}
}

