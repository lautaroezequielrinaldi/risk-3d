#include "glwidget.h"

GLWidget::GLWidget(const int& x, const int& y, const int& width,
	const int& height, const bool& visible, const bool& enabled):
	mouseButtonListenerList(),
	x(x),
	y(y),
	width(width),
	height(height),
	visible(visible),
	enabled(enabled) {
	// No realiza ninguna accion.
}

void GLWidget::fireMouseButtonNotification(const SDL_MouseButtonEvent& event) {
	std::list<MouseButtonListener*>::iterator iterator;

	for (iterator = this->mouseButtonListenerList.begin();
		iterator != this->mouseButtonListenerList.end(); ++iterator) {
		MouseButtonListener* listener = *iterator;
		listener->mouseButtonEventFired(event);
	}
}

bool GLWidget::containsPoint(const int& x, const int& y) {
	if ( (x >= this->x && x <= (this->width + this->x) ) &&
		(y >= this->y && y <= (this->height + this->y) ) ) {
		return true;
	}
	return false;
}

void GLWidget::setX(const int& x) {
	this->x = x;
}

int GLWidget::getX() const {
	return this->x;
}

void GLWidget::setY(const int& y) {
	this->y = y;
}

int GLWidget::getY() const {
	return this->y;
}

void GLWidget::setWidth(const int& width) {
	this->width = width;
}

int GLWidget::getWidth() const {
	return this->width;
}

void GLWidget::setHeight(const int& height) {
	this->height = height;
}

int GLWidget::getHeight() const {
	return this->height;
}

void GLWidget::setVisible(const bool& visible) {
	this->visible = visible;
}

bool GLWidget::getVisible() const {
	return this->visible;
}

void GLWidget::setEnabled(const bool& enabled) {
	this->enabled = enabled;
}

bool GLWidget::getEnabled() const {
	return this->enabled;
}

void GLWidget::registerMouseButtonListener(MouseButtonListener* listener) {
	this->mouseButtonListenerList.push_back(listener);
}

void GLWidget::unregisterMouseButtonListener(MouseButtonListener* listener) {
	this->mouseButtonListenerList.remove(listener);
}

void GLWidget::processMouseButtonEvent(
	const SDL_MouseButtonEvent& event) {
	if (this->enabled) {
		if (this->containsPoint(event.x, event.y)) {
			this->fireMouseButtonNotification(event);
		}
	}
}

GLWidget::~GLWidget() {
	// No realiza ninguna accion.
}

