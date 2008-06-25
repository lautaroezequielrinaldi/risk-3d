#include "glbutton.h"
#include<iostream>
void GLButton::drawWidget() {
	// Obtengo la dimension del widget.
    Dimension dimension = this->getDimension();

	// Verifica el tipo de estado.
	switch ( this->getState() ) {
		// Widget activo, dibujo widget activo.
		case GLWIDGET_ACTIVE: {
			// Obtengo color background para widget activo.
			Color background = this->getBackgroundColor(GLWIDGET_ACTIVE);
			// Obtengo el color foreground para widget activo.
			Color foreground = this->getForegroundColor(GLWIDGET_ACTIVE);
			// Dibuja el fondo del boton.
			GLDrawHelper::drawFillRectangle(dimension.getX(), dimension.getWidth(), dimension.getY(),
				dimension.getHeight(), background);
			// Dibuja el texto del boton.
			GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
			break;
		}
		// Widget inactivo, dibujo widget inactivo.
		case GLWIDGET_INACTIVE: {
            // Obtengo color background para widget inactivo.
            Color background = this->getBackgroundColor(GLWIDGET_INACTIVE);
            // Obtengo el color foreground para widget inactivo.
            Color foreground = this->getForegroundColor(GLWIDGET_INACTIVE);
			// Dibuja el fondo del boton.
            GLDrawHelper::drawFillRectangle(dimension.getX(), dimension.getWidth(), dimension.getY(),
                dimension.getHeight(), background);
			// Dibuja el texto del boton.
            GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
			break;
		}
		// Widget focus, dibujo widget focus.
		case GLWIDGET_FOCUS: {
            // Obtengo color background para widget focus.
            Color background = this->getBackgroundColor(GLWIDGET_FOCUS);
            // Obtengo color foreground para widget focus.
            Color foreground = this->getForegroundColor(GLWIDGET_FOCUS);
			// Dibuja el fondo del boton.
            GLDrawHelper::drawFillRectangle(dimension.getX(), dimension.getWidth(), dimension.getY(),
                dimension.getHeight(), background);
			// Dibuja el texto del boton.
            GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
			break;
		}
	}
}

GLButton::GLButton(const std::string& text): GL2DWidget(), text(text) {
	// No realiza ninguna accion.
}

GLButton::GLButton(const Dimension& dimension, const bool& visible, const bool& enabled, const std::string& text):
	GL2DWidget(dimension, visible, enabled), text(text) {
	// No realiza ninguna accion.
}

std::string GLButton::getText() {
	return this->text;
}

void GLButton::setText(const std::string& text) {
	this->text = text;
}

GLButton::~GLButton() {
	// No realiza ninguna accion.
}

