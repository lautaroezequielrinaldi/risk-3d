#include "uimouseinformation.h"

UIMouseInformation::UIMouseInformation():
    releaseStatus(0),
    buttonStatus(0),
    x(0),
    y(0) {
    // No realiza ninguna acciòn.
}

Uint8 UIMouseInformation::getReleaseStatus() const {
    return this->releaseStatus;
}

void UIMouseInformation::setReleaseStatus(const Uint8& releaseStatus) {
    this->releaseStatus = releaseStatus;
}

Uint8 UIMouseInformation::getButtonStatus() const {
    return this->buttonStatus;
}

void UIMouseInformation::setButtonStatus(const Uint8& buttonStatus) {
    this->buttonStatus = buttonStatus;
}

Uint16 UIMouseInformation::getX() const {
    return this->x;
}

void UIMouseInformation::setX(const Uint16& x) {
    this->x = x;
}

Uint16 UIMouseInformation::getY() const {
    return this->y;
}

void UIMouseInformation::setY(const Uint16& y) {
    this->y = y;
}

UIMouseInformation::~UIMouseInformation() {
    // No realiza ninguna acciòn.
}

