#include "glwidget.h"

GLWidget::GLWidget(const int& x, const int& y, const int& width,
	const int& height, const bool& visible, const bool& enabled,
	const bool& hoover):
	bounds(x, y, width, height),
	shadowColor(1.0f, 0.0f, 0.0f),
	backgroundColor(0.5f, 0.5f, 0.5f),
	foregroundColor(1.0f, 1.0f, 1.0f),
	hooverColor(1.0f, 1.0f, 1.0f),
	visible(visible),
	enabled(enabled),
	hoover(hoover) {
	// No realiza ninguna accion.
}

Rectangle GLWidget::getBounds() {
	return this->bounds;
}

void GLWidget::setBounds(const Rectangle& bounds) {
	this->bounds = bounds;
}

Color GLWidget::getShadowColor() {
	return this->shadowColor;
}

void GLWidget::setShadowColor(const Color& color) {
	this->shadowColor = color;
}

Color GLWidget::getBackgroundColor() {
    return this->backgroundColor;
}

void GLWidget::setBackgroundColor(const Color& color) {
    this->backgroundColor = color;
}

Color GLWidget::getForegroundColor() {
    return this->foregroundColor;
}

void GLWidget::setForegroundColor(const Color& color) {
    this->foregroundColor = color;
}

Color GLWidget::getHooverColor() {
    return this->hooverColor;
}

void GLWidget::setHooverColor(const Color& color) {
    this->hooverColor = color;
}

bool GLWidget::getVisible() {
	return this->visible;
}

void GLWidget::setVisible(const bool& visible) {
	this->visible = visible;
}

bool GLWidget::getEnabled() {
	return this->enabled;
}

void GLWidget::setEnabled(const bool& enabled) {
	this->enabled = enabled;
}

bool GLWidget::getHoover() {
    return this->hoover;
}

void GLWidget::setHoover(const bool& hoover) {
    this->hoover = hoover;
}

void GLWidget::preDrawWidget() {
	// Guarda en el stack la matriz actual.
	glPushMatrix();
	// Guarda en el stack los atributos actuales.
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	// Deshabilita DEPTH.
	glDisable(GL_DEPTH_TEST);
	// Carga la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// Carga la identidad.
	glLoadIdentity();
	// Establece coordenadas 2D.
	glOrtho(0, 1024, 768, 0, 0, 1);
	// Carga la matriz model view.
	glMatrixMode(GL_MODELVIEW);
}

void GLWidget::postDrawWidget() {
	// Carga del stack los atributos.
	glPopAttrib();
	// Carga del sack la matriz actual.
	glPopMatrix();
}

void GLWidget::becomeIdle() {
	SDL_Delay(100);
}

void GLWidget::drawQuadrangle(GLenum polygonType, GLint left, GLint right,
	GLint bottom, GLint top, Color color) {
	glBegin(polygonType);
        glColor3f(color.red, color.green, color.blue);
		glVertex2i(left, bottom);
		glColor3f(color.red, color.green, color.blue);	
		glVertex2i(left, top);
        glColor3f(color.red, color.green, color.blue);
		glVertex2i(right, top);
        glColor3f(color.red, color.green, color.blue);
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

