#include "button.h"

Button::Button(UIState& uiState): Widget(uiState), text() {
	// No realiza ninguna accion.
}

Button::Button(UIState& uiState, const std::string& text, const float& x,
	const float& y, const float& width, const float& height,
	const bool& visible, const bool& enabled):
	Widget(uiState, x, y, width, height, visible, enabled),
	text(text) {
	// No realiza ninguna accion.
}

void Button::setText(const std::string& text) {
	this->text = text;
}

std::string Button::getText() const {
	return this->text;
}

bool Button::doProcess() {
	if ( getVisible() ) {
		// Define el color
		ColorRGB color;

		ColorRGB textColor;
		textColor.red = 1.0f;
		textColor.green = 1.0f;
		textColor.blue = 1.0f;

		if ( isMouseOver() && getEnabled() ) {
			getUIState().setHotItem( getId() );
			if ( getUIState().getActiveItem() == ItemHandler::ID_NOT_SELECTED
				&& getUIState().getMousePressed() ) {
				getUIState().setActiveItem( getId() );
			}
		}
		// Defino color
		color.red = 1.0f;
		color.green = 1.0f;
		color.blue = 1.0f;
		// Dibuja el rectangulo
		drawFilledRectangle(getX() + 8, getY() + 8, getWidth(), getHeight(), color);
		if ( getUIState().getHotItem() == getId() ) {
			if ( getUIState().getActiveItem() == getId() ) {
				// Defino el color
				color.red = 1.0;
				color.green = 0.0f;
				color.blue = 0.0;
				// Dibujo el rectangulo
				drawFilledRectangle(getX() + 2, getY() + 2, getWidth(), getHeight(),
					 color);
				drawCenteredText(getText(), getX() + 2, getY() + 2, getWidth(), getHeight(), textColor);
			} else {
				// Defino el color
			    color.red = 1.0;
				color.green = 0.0f;
	            color.blue = 0.0;
		        // Dibujo el rectangulo
			    drawFilledRectangle(getX(), getY(), getWidth(), getHeight(),
				    color);
				drawCenteredText(getText(), getX(), getY(), getWidth(), getHeight(), textColor);
			}
		} else {
			// Defino color
			color.red = 0.0f;
			color.green = 0.0f;
			color.blue = 1.0f;
			drawFilledRectangle(getX(), getY(), getWidth(), getHeight(),
				 color);
			drawCenteredText(getText(), getX(), getY(), getWidth(), getHeight(), textColor);
		}
		if ( !getUIState().getMousePressed() && 
	      getUIState().getHotItem() == getId() && 
		  getUIState().getActiveItem() == getId()) { 
			return true;
		}
		return false;
	}
}
Button::~Button() {
	// No realiza ninguna accion.
}

