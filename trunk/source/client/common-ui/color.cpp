#include "color.h"

const Color Color::WHITE(1.0f, 1.0f, 1.0f);
const Color Color::BLACK(0.0f, 0.0f, 0.0f);
const Color Color::GRAY(0.5f, 0.5f, 0.5f);
const Color Color::RED(1.0f, 0.0f, 0.0f);
const Color Color::GREEN(0.0f, 1.0f, 0.0f);
const Color Color::BLUE(0.0f, 0.0f, 1.0f);

Color::Color(const float& red, const float& green, const float& blue):
	red(red),
	green(green),
	blue(blue) {
	// No realiza ninguna accion.
}

float Color::getRed() {
	return this->red;
}

void Color::setRed(const float& red) {
	this->red = red;
}

float Color::getGreen() {
    return this->green;
}

void Color::setGreen(const float& green) {
    this->green = green;
}

float Color::getBlue() {
    return this->blue;
}

void Color::setBlue(const float& blue) {
    this->blue = blue;
}

