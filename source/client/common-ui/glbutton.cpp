#include "glbutton.h"
#include <iostream>
GLButton::GLButton(const int& x, const int& y, const int& width,
	const int& height, const bool& visible, const bool& enabled):
	GLWidget(x, y, width, height, visible, enabled) {
	// No realiza ninguna accion.
}

void GLButton::drawWidget() {
	this->drawQuadrangle(GL_QUADS, bounds.getX() - 10, bounds.getWidth() - 10,
        bounds.getY() - 10, bounds.getHeight() - 10, shadowColor);
	this->drawQuadrangle(GL_QUADS, bounds.getX(), bounds.getWidth(),
		bounds.getY(), bounds.getHeight(), backgroundColor);
    this->drawQuadrangle(GL_LINE_LOOP, bounds.getX() - 1 ,
		bounds.getWidth() + 1, bounds.getY() - 1, bounds.getHeight() + 1,
		foregroundColor);
}

void GLButton::processMouseButton(const SDL_MouseButtonEvent& event) {
	if (this->contains(event.x, event.y)) {
		std::cout << "Se presiono" << std::endl;
	} else {
		std::cout << "No se presiono" << std::endl;
	}
}

void GLButton::processMouseMotion(const SDL_MouseMotionEvent& event) {

}

void GLButton::processKeyboard(const SDL_KeyboardEvent& event) {

}

GLButton::~GLButton() {
	// No realiza ninguna accion.
}

