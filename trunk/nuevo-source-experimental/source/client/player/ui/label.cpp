#include "label.h"

Label::Label(UIState& uiState, const std::string& text, const float& x, const float& y,
	const float& width, const float& height, const bool& visible,
	const bool& enabled): Widget(uiState, x, y, width, height, visible,
	enabled) {
	// No realiza ninguna accion.
}

bool Label::doProcess() {
	return false;
}

Label::~Label() {
	// No realiza ninguna accion.
}

