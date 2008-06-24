#include "buttonwidget.h"
#include <iostream>

ButtonWidget::ButtonWidget(const int& x, const int& y, const int& width,
    const int& height, const bool& visible, const bool& enabled):
	GLWidget(x, y, width, height, visible, enabled) {
	// No realiza ninguna accion.
}

void ButtonWidget::draw() {
	if (this->getVisible()) {
		UIManager::getInstance().getDisplayManager().drawRectangle(getX(), getY(), getWidth(), getHeight(), 0xff);
		std::cout << "Se dibujo" << std::endl;
	} else {
		std::cout << "No es visible" << std::endl;
	}
}

ButtonWidget::~ButtonWidget() {
	// No realiza ninguna accion.
}

