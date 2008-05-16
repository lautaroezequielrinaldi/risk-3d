#include "uihandler.h"

UIHandler::UIHandler(int elementId):
    ownerId(0),
    elementId(elementId),
    arrayIndex(0) {
    // No realiza ninguna acciòn.
}

int UIHandler::getOwnerId() {
    return this->ownerId;
}

void UIHandler::setOwnerId(int ownerId) {
    this->ownerId = ownerId;
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

UIHandler::~UIHandler() {
    // No realiza ninguna acciòn.
}

