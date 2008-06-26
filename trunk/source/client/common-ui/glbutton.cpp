#include "glbutton.h"

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
			GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() +  dimension.getWidth(),
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
            GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() +  dimension.getWidth(),
                dimension.getY(), dimension.getY() + dimension.getHeight(), background);
			// Dibuja el texto del boton.
            GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
			break;
		}
		// Widget focus, dibujo widget focus.
		case GLWIDGET_DISABLED: {
            // Obtengo color background para widget focus.
            Color background = this->getBackgroundColor(GLWIDGET_DISABLED);
            // Obtengo color foreground para widget focus.
            Color foreground = this->getForegroundColor(GLWIDGET_DISABLED);
			// Dibuja el fondo del boton.
            GLDrawHelper::drawFilledRectangle(dimension.getX(), dimension.getX() +  dimension.getWidth(),
                dimension.getY(), dimension.getY() + dimension.getHeight(), background);
			// Dibuja el texto del boton.
            GLDrawHelper::drawCenteredText(this->getText(), dimension, foreground);
			// Corta la secuencia.
			break;
		}
	}
}

void GLButton::handleMouseButtonDownEvent(const SDL_MouseButtonEvent& event) {
	// Invoca al metodo padre
	GLWidget::handleMouseButtonDownEvent(event);
	if (this->getEnabled()) {
		// Si se presiono notifica del evento.
		if ( getDimension().contains(event.x, event.y) ) {
			notifyMouseButtonDownEvent(event);
		}
	}
}

void GLButton::handleMouseButtonUpEvent(const SDL_MouseButtonEvent& event) {
	// Invoca al metodo padre
	GLWidget::handleMouseButtonUpEvent(event);
	if (this->getEnabled()) {
		// Si se solto notifica del evento.
		if ( getDimension().contains(event.x, event.y) ) {
			notifyMouseButtonUpEvent(event);
		}
	}
}

void GLButton::handleMouseMotionEvent(const SDL_MouseMotionEvent& event) {
	// Invoca al metodo padre
	GLWidget::handleMouseMotionEvent(event);
	// Si se movio notifica del evento
	if ( getDimension().contains(event.x, event.y) ) {
		notifyMouseMotionEvent(event);
	}
}

GLButton::GLButton(const std::string& text): GL2DWidget(), MouseObservable(), text(text) {
	// No realiza ninguna accion.
	int widgetWidth = GLDrawHelper::calculateTextWidth(text, 10);
	int widgetHeight = GLDrawHelper::calculateTextHeight(text, 10);
	this->setWidth(widgetWidth);
	this->setHeight(widgetHeight);
}

std::string GLButton::getText() {
	return this->text;
    int widgetWidth = GLDrawHelper::calculateTextWidth(text, 10);
    int widgetHeight = GLDrawHelper::calculateTextHeight(text, 10);
    this->setWidth(widgetWidth);
    this->setHeight(widgetHeight);
}

void GLButton::setText(const std::string& text) {
	this->text = text;
}

GLButton::~GLButton() {
	// No realiza ninguna accion.
}

