#include "glwidget.h"

long GLWidget::idCounter = 0;

void GLWidget::incrementIdCounter() {
	++GLWidget::idCounter;
}

long GLWidget::getIdCounter() {
	return GLWidget::idCounter;
}

long GLWidget::getId() {
	return this->id;
}

void GLWidget::setId(const long& id) {
	this->id = id;
}

GLWidgetStateType GLWidget::getState() {
	return this->state;
}

void GLWidget::setState(const GLWidgetStateType& type) {
	this->state = type;
}

GLWidget::GLWidget() {
	// Incrementa el contador de widget.
	GLWidget::incrementIdCounter();
	// Establece el id de widget.
	this->setId(GLWidget::getIdCounter());
	// Establece el estado visible del widget.
	this->setVisible(true);
	// Establece el estado habilitado del widget.
	this->setEnabled(true);
	// Establece el estado del widget como inactivo.
	this->setState(GLWIDGET_INACTIVE);
	// Llena el mapa de color background del widget.
	this->backgroundColorMap[GLWIDGET_ACTIVE] = Color::GRAY;
	this->backgroundColorMap[GLWIDGET_INACTIVE] = Color::GRAY;
	this->backgroundColorMap[GLWIDGET_FOCUS] = Color::GRAY;
	// Llena el mapa de color foreground del widget.
	this->foregroundColorMap[GLWIDGET_ACTIVE] = Color::BLACK;
	this->foregroundColorMap[GLWIDGET_INACTIVE] = Color::WHITE;
	this->foregroundColorMap[GLWIDGET_FOCUS] = Color::BLACK;
}

GLWidget::GLWidget(const Dimension& dimension, const bool& visible, const bool& enabled) {
    // Incrementa el contador de widget.
    GLWidget::incrementIdCounter();
    // Establece el id de widget.
    this->setId(GLWidget::getIdCounter());
    // Establece el estado visible del widget.
    this->setVisible(visible);
    // Establece el estado habilitado del widget.
    this->setEnabled(enabled);
    // Establece el estado del widget como inactivo.
    this->setState(GLWIDGET_INACTIVE);
    // Llena el mapa de color background del widget.
    this->backgroundColorMap[GLWIDGET_ACTIVE] = Color::GRAY;
    this->backgroundColorMap[GLWIDGET_INACTIVE] = Color::GRAY;
    this->backgroundColorMap[GLWIDGET_FOCUS] = Color::GRAY;
    // Llena el mapa de color foreground del widget.
    this->foregroundColorMap[GLWIDGET_ACTIVE] = Color::BLACK;
    this->foregroundColorMap[GLWIDGET_INACTIVE] = Color::WHITE;
    this->foregroundColorMap[GLWIDGET_FOCUS] = Color::BLACK;
}

Dimension& GLWidget::getDimension() {
	return this->dimension;
}

void GLWidget::setDimension(const Dimension& dimension) {
	this->dimension = dimension;
}

void GLWidget::setX(const int& x) {
	this->dimension.setX(x);
}

void GLWidget::setY(const int& y) {
    this->dimension.setY(y);
}

void GLWidget::setWidth(const int& width) {
    this->dimension.setWidth(width);
}

void GLWidget::setHeight(const int& height) {
    this->dimension.setHeight(height);
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

Color GLWidget::getBackgroundColor(const GLWidgetStateType& type) {
	return backgroundColorMap[type];
}

void GLWidget::setBackgroundColor(const GLWidgetStateType& type, const Color& color) {
	this->backgroundColorMap[type] = color;
}

Color GLWidget::getForegroundColor(const GLWidgetStateType& type) {
    return foregroundColorMap[type];
}

void GLWidget::setForegroundColor(const GLWidgetStateType& type, const Color& color) {
    this->foregroundColorMap[type] = color;
}

void GLWidget::draw() {
	this->preDrawWidget();
	this->drawWidget();
	this->postDrawWidget();
}

GLWidget::~GLWidget() {
	// No realiza ninguna accion.
}

