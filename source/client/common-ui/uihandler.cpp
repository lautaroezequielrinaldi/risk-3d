#include "uihandler.h"

UIHandler::UIHandler(int elementId):
    elementId(elementId),
    arrayIndex(0) {
    // No realiza ninguna acciòn.
}

int UIHandler::getElementId() {
    return this->elementId;
}

void UIHandler::setElementId(int elementId) {
    this->elementId = elementId;
}

int UIHandler::getArrayIndex() {
    return this->arrayIndex;
}

void UIHandler::setArrayIndex(int arrayIndex) {
    this->arrayIndex = arrayIndex;
}

bool UIHandler::operator==(const UIHandler& otherInstance) {
    bool result = (this->elementId == otherInstance.elementId) &&
                  (this->arrayIndex == otherInstance.arrayIndex);

    return result;
}

bool UIHandler::operator!=(const UIHandler& otherInstance) {
    bool result = (*this == otherInstance);
    return !result;
}

UIHandler::~UIHandler() {
    // No realiza ninguna acciòn.
}

