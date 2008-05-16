#include "uicontext.h"

UIContext::UIContext():
	hotItem(0),
	activeItem(0),
	mouseInformation(new UIMouseInformation),
	keyboardInformation(new UIKeyboardInformation) {
	// No realiza ninguna acciÛn
}

UIHandler UIContext::getHotItem() {
    return this->hotItem;
}

void UIContext::setHotItem(UIHandler hotItem) {
    this->hotItem = hotItem;
}

UIHandler UIContext::getActiveItem() {
    return this->activeItem;
}

void UIContext::setActiveItem(UIHandler activeItem) {
    this->activeItem = activeItem;
}

ReferenceCountPtr<UIMouseInformation> UIContext::getMouseInformation() {
    return this->mouseInformation;
}

void UIContext::setMouseInformation(
    ReferenceCountPtr<UIMouseInformation> mouseInformation) {
    this->mouseInformation = mouseInformation;
}

ReferenceCountPtr<UIKeyboardInformation> UIContext::getKeyboardInformation() {
    return this->keyboardInformation;
}

void UIContext::setKeyboardInformation(
    ReferenceCountPtr<UIKeyboardInformation> keyboardInformation) {
    this->keyboardInformation = keyboardInformation;
}

UIContext::~UIContext() {
    // No realiza ninguna acci√≤n.
}

