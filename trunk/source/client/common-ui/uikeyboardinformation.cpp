#include "uikeyboardinformation.h"

UIKeyboardInformation::UIKeyboardInformation() {
    // Itero por cada tecla del teclado.
    for (int counter = SDLK_FIRST; counter < SDLK_LAST; ++counter) {
        // Marco tecla como no presionada.
        this->keyboard[counter] = false;
    }
}

void UIKeyboardInformation::markKeyPressed(SDLKey key) {
    this->keyboard[key] = true;
}

void UIKeyboardInformation::markKeyUnpressed(SDLKey key) {
    this->keyboard[key] = false;
}

bool UIKeyboardInformation::isKeyPressed(SDLKey key) {
    return this->keyboard[key];
}

UIKeyboardInformation::~UIKeyboardInformation() {
    // No realiza ninguna acciòn.
}

