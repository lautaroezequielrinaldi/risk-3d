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

void GLDrawHelper::drawText(const std::string& text, const GLint& x, const GLint& y, Color& color) {
    glColor3f(color.getRed(), color.getGreen(), color.getBlue());
	glRasterPos2f(x, y);
	for (int counter = 0; counter < text.size(); ++ counter) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[counter]);
	}
}

