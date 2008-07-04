#include "widget.h"

Widget::Widget(UIState& uiState):
	uiState(uiState),
	x(0),
	y(0),
	width(0),
	height(0),
	visible(false),
	enabled(false) {
	// No realiza ninguna accion.
}

Widget::Widget(UIState& uiState, const float& x, const float& y,
	const float& width, const float& height, const bool& visible,
	const bool& enabled):
	uiState(uiState),
	id(ItemHandler::generateNextItemId()),
	x(x),
	y(y),
	width(width),
	height(height),
	visible(visible),
	enabled(enabled) {
	// No realizqa ninguna accion.
}

bool Widget::isMouseOver() const {
if (getUIState().getMouseX() < getX() ||
      getUIState().getMouseY() < getY() ||
      getUIState().getMouseX() >= getX() + getWidth() ||
      getUIState().getMouseY() >= getY() + getHeight())
    return false;
  return true;
}

void Widget::setUIState(const UIState& uiState) {
	this->uiState = uiState;
}

UIState& Widget::getUIState() const {
	return this->uiState;
}

int Widget::getId() const {
	return this->id;
}

void Widget::setX(const float& x) {
	this->x = x;
}

float Widget::getX() const {
	return this->x;
}

void Widget::setY(const float& y) {
    this->y = y;
}

float Widget::getY() const {
    return this->y;
}

void Widget::setWidth(const float& width) {
    this->width = width;
}

float Widget::getWidth() const {
    return this->width;
}

void Widget::setHeight(const float& height) {
    this->height = height;
}

float Widget::getHeight() const {
    return this->height;
}

void Widget::setVisible(const bool& visible) {
    this->visible = visible;
}

bool Widget::getVisible() const {
    return this->visible;
}

void Widget::setEnabled(const bool& enabled) {
    this->enabled = enabled;
}

bool Widget::getEnabled() const {
    return this->enabled;
}

Widget::~Widget() {
	// No realiza ninguna accion.
}

