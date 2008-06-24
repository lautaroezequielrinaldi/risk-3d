#include "glwidget.h"

GLWidget::GLWidget(const int& x, const int& y, const int& width,
	const int& height, const bool& visible, const bool& enabled):
	bounds(x, y, width, height),
	visible(visible),
	enabled(enabled) {
	// No realiza ninguna accion.
}

Rectangle GLWidget::getBounds() {
	return this->bounds;
}

void GLWidget::setBounds(const Rectangle& bounds) {
	this->bounds = bounds;
}

void GLWidget::preDrawWidget() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glLoadIdentity();
	glTranslatef(this->bounds.getX(), this->bounds.getY(), 0);
}

void GLWidget::postDrawWidget() {
	glPopAttrib();
	glPopMatrix();
}

void GLWidget::becomeIdle() {
	// No realiza ninguna accion.
}

void GLWidget::drawQuadrangle(int polygonType, int left, int right,
	int bottom, int top) {
	glBegin(polygonType);
		glVertex2i(left, bottom);
		glVertex2i(left, top);
		glVertex2i(right, top);
		glVertex2i(right, bottom);
	glEnd();
}

bool GLWidget::contains(const int& x, const int& y) {
	return this->bounds.contains(x, y);
}

void GLWidget::draw() {
	if (this->visible) {
		this->preDrawWidget();
		this->drawWidget();
		this->postDrawWidget();
	}
}

GLWidget::~GLWidget() {
	// No realiza ninguna accion.
}

