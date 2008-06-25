#include "dimension.h"

Dimension::Dimension(const int& x, const int& y, const int& width, const int& height):
	x(x),
	y(y),
	width(width),
	height(height) {
	// No realiza ninguna accion.
}

int Dimension::getX() {
	return this->x;
}

void Dimension::setX(const int& x) {
	this->x = x;
}

int Dimension::getY() {
	return this->y;
}

void Dimension::setY(const int& y) {
	this->y = y;
}

int Dimension::getWidth() {
	return this->width;
}

void Dimension::setWidth(const int& width) {
	this->width = width;
}

int Dimension::getHeight() {
	return this->height;
}

void Dimension::setHeight(const int& height) {
	this->height = height;
}

