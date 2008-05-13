#include "uicontext.h"

UIContext::UIContext() {
    // No realiza ninguna acciòn.
}

UIHandler& UIContext::getHotItem() {
    return this->hotItem;
}

void UIContext::setHotItem(const UIHandler& hotItem) {
    this->hotItem = hotItem;
}

UIHandler& UIContext::getActiveItem() {
    return this->activeItem;
}

void UIContext::setActiveItem(const UIHandler& activeItem) {
    this->activeItem = activeItem;
}

UIMouseInformation& UIContext::getMouseInformation() {
    return this->mouseInformation;
}

void UIContext::setMouseInformation(
    const UIMouseInformation& mouseInformation) {
    this->mouseInformation = mouseInformation;
}

UIKeyboardInformation& UIContext::getKeyboardInformation() {
    return this->keyboardInformation;
}

void UIContext::setKeyboardInformation(
    const UIKeyboardInformation& keyboardInformation) {
    this->keyboardInformation = keyboardInformation;
}

UIContext::~UIContext() {
    // No realiza ninguna acciòn.
}

