#include "button.h"

Button::Button(UIState& uiState, const float& x, const float& y,
	const float& width, const float& height, const bool& visible,
	const bool& enabled): Widget(uiState, x, y, width, height, visible,
	enabled) {
	// No realiza ninguna accion.
}

bool Button::doProcess() {
	// Define el color
	ColorRGB color;
	if ( isMouseOver() ) {
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
		} else {
			// Defino el color
            color.red = 1.0;
            color.green = 0.0f;
            color.blue = 0.0;
            // Dibujo el rectangulo
            drawFilledRectangle(getX(), getY(), getWidth(), getHeight(),
	            color);
		}
	} else {
		// Defino color
		color.red = 0.0f;
		color.green = 0.0f;
		color.blue = 1.0f;
		drawFilledRectangle(getX(), getY(), getWidth(), getHeight(),
			 color);
	}
	if ( !getUIState().getMousePressed() && 
      getUIState().getHotItem() == getId() && 
      getUIState().getActiveItem() == getId()) { 
	    return true;
	}
	return false;
}

Button::~Button() {
	// No realiza ninguna accion.
}

