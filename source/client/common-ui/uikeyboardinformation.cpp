#include "uikeyboardinformation.h"

UIKeyboardInformation() {
    // Itero por cada tecla del teclado.
    for (int counter = 0; counter < SDLK_MAX; ++counter) {
        // Marco tecla como no presionada.
        this->keyboard[counter] = false;
    }
};

void UIKeyboardInformation::markKeyPressed(int key) {
    this->keyboard[key] = true;
}

void UIKeyboardInformation::markKeyUpressed(int key) {
    this->keyboard[key] = false;
}

bool UIKeyboardInformation::isKeyPressed(int key) {
    return this->keyboard[key];
}

UIKeyboardInformation::~UIKeyboardInformation() {
    // No realiza ninguna acciòn.
}

