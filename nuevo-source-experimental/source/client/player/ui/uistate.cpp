#include "uistate.h"

UIState::UIState():
	activeItem(ItemHandler::INVALID_ID),
	hotItem(ItemHandler::INVALID_ID),
	mouseX(0),
	mouseY(0),
	mousePressed(false) {
    // Inicializo mapa de teclas en false
    for (int counter = 0; counter < SDLK_LAST; ++counter) {
        keyMap[counter] = false;
    }
}

void UIState::setActiveItem(const int& activeItem) {
	this->activeItem = activeItem;
}

int UIState::getActiveItem() const {
	return this->activeItem;
}

void UIState::setHotItem(const int& hotItem) {
    this->hotItem = hotItem;
}

int UIState::getHotItem() const {
    return this->hotItem;
}

void UIState::setMouseX(const int& mouseX) {
    this->mouseX = mouseX;
}

int UIState::getMouseX() const {
    return this->mouseX;
}

void UIState::setMouseY(const int& mouseY) {
    this->mouseY = mouseY;
}

int UIState::getMouseY() const {
    return this->mouseY;
}

void UIState::setMousePressed(const bool& mousePressed) {
    this->mousePressed = mousePressed;
}

int UIState::getMousePressed() const {
    return this->mousePressed;
}

void UIState::prepare() {
	this->setHotItem( ItemHandler::ID_NOT_SELECTED );
}

void UIState::unprepare() {
	if ( !this->getMousePressed() ) {
		this->setActiveItem( ItemHandler::ID_NOT_SELECTED );
	} else {
		if ( this->getActiveItem() == ItemHandler::ID_NOT_SELECTED) {
			this->setActiveItem( ItemHandler::INVALID_ID );
		}
	}
}

void UIState::setKeyPressed(const SDLKey& key, bool pressed) {
    keyMap[key] = pressed;
}

bool UIState::getKeyPressed(const SDLKey& key) const {
    return keyMap[key];
}

UIState::~UIState() {
	// No realiza ninguna accion.
}

