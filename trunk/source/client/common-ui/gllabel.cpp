#include "gllabel.h"

void GLLabel::drawWidget() {
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
	        // Dibuja el fondo del label.
            GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() + dimension.getWidth(),
				dimension.getY(), dimension.getY() + dimension.getHeight(), background);
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
            GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() + dimension.getWidth(),
                dimension.getY(), dimension.getY() + dimension.getHeight(), background);
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
            GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() + dimension.getWidth(),
                dimension.getY(), dimension.getY() + dimension.getHeight(), background);
			// Dibuja el texto del boton.
            GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
            break;
		}
	}
}

GLLabel::GLLabel(const std::string& text): GL2DWidget(), text(text) {
    // No realiza ninguna accion.
    int widgetWidth = GLDrawHelper::calculateTextWidth(text, 10);
    int widgetHeight = GLDrawHelper::calculateTextHeight(text, 10);
    this->setWidth(widgetWidth);
    this->setHeight(widgetHeight);
}

std::string GLLabel::getText() {
    return this->text;
}

void GLLabel::setText(const std::string& text) {
    this->text = text;
    int widgetWidth = GLDrawHelper::calculateTextWidth(text, 10);
    int widgetHeight = GLDrawHelper::calculateTextHeight(text, 10);
    this->setWidth(widgetWidth);
    this->setHeight(widgetHeight);

}

GLLabel::~GLLabel() {
    // No realiza ninguna accion.
}

