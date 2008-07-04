#include "label.h"

Label::Label(UIState& uiState): Widget(uiState), text(text) {
	// No realiza ninguna accion.
}

Label::Label(UIState& uiState, const std::string& text, const float& x, const float& y,
	const float& width, const float& height, const bool& visible,
	const bool& enabled): Widget(uiState, x, y, width, height, visible,
	enabled), text(text) {
	// No realiza ninguna accion.
}

bool Label::doProcess() {
	if ( getVisible()) {
		ColorRGB color;
		ColorRGB textColor;

		color.red = 1.0;
		color.green = 0.0f,
		color.blue = 0.0f;
		
		textColor.red = 1.0f;
		textColor.green = 1.0f;
		textColor.blue = 1.0f;

		drawFilledRectangle(getX(), getY(), getWidth(), getHeight(), color);
		drawCenteredText(getText(), getX(), getY(), getWidth(), getHeight(), textColor);
	}
	return false;
}

std::string Label::getText() const {
	return this->text;
}

Label::~Label() {
	// No realiza ninguna accion.
}

