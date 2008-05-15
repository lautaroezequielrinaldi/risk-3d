#include "uicontext.h"

UIContext::UIContext():
	hotItem(new UIHandler),
	activeItem(new UIHandler)
	mouseInformation(new UIMouseInformation),
	keyboardInformation(new UIKeyboardInformation) {
	// No realiza ninguna acción
}

ReferenceCountPtr<UIHandler> UIContext::getHotItem() {
    return this->hotItem;
}

void UIContext::setHotItem(ReferenceCoutnPtr<UIHandler> hotItem) {
    this->hotItem = hotItem;
}

ReferenceCountPtr<UIHandler> UIContext::getActiveItem() {
    return this->activeItem;
}

void UIContext::setActiveItem(ReferenceCountPtr<UIHandler> activeItem) {
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
    // No realiza ninguna acciÃ²n.
}

