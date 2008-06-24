#include "rectangle.h"

Rectangle::Rectangle():
	x(0),
	y(0),
	width(0),
	height(0) {
	// No realiza ninguna accion.
}

Rectangle::Rectangle(const int& x, const int& y, const int& width,
	const int& height):
	x(x),
	y(y),
	width(width),
	height(height) {
	// No realiza ninguna accion.
}

int Rectangle::getX() {
	return this->x;
}

void Rectangle::setX(const int& x) {
	this->x = x;
}

int Rectangle::getY() {
    return this->y;
}

void Rectangle::setY(const int& Y) {
    this->y = y;
}

int Rectangle::getWidth() {
    return this->width;
}

void Rectangle::setWidth(const int& width) {
    this->width = width;
}

int Rectangle::getHeight() {
    return this->height;
}

void Rectangle::setHeight(const int& height) {
    this->height = height;
}

bool Rectangle::contains(const int& x, const int& y) {
	if ( ( (x >= this->x) && (x <= this->x + this->width) ) &&
		( (y >= this->y) && ( y <= this->y + this->height) ) ) {
		return true;
	}
	return false;
}

Rectangle::~Rectangle() {
	// No realiza ninguna accion.
}

