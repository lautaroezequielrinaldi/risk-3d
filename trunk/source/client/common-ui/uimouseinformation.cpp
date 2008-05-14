#include "uimouseinformation.h"

UIMouseInformation::UIMouseInformation():
    releaseStatus(MOUSE_RELEASE_NONE),
    buttonStatus(MOUSE_BUTTON_NONE),
    x(0),
    y(0) {
    // No realiza ninguna acciòn.
}

MouseReleaseStatus& UIMouseInformation::getReleaseStatus() {
    return this->releaseStatus;
}

void UIMouseInformation::setReleaseStatus(
    const MouseReleaseStatus& releaseStatus) {
    this->releaseStatus = releaseStatus;
}

MouseButtonStatus& UIMouseInformation::getButtonStatus() {
    return this->buttonStatus;
}

void UIMouseInformation::setButtonStatus(
    const MouseButtonStatus& buttonStatus) {
    this->buttonStatus = buttonStatus;
}

int UIMouseInformation::getX() {
    return this->x;
}

void UIMouseInformation::setX(int x) {
    this->x = x;
}

int UIMouseInformation::getY() {
    return this->y;
}

void UIMouseInformation::setY(int y) {
    this->y = y;
}

UIMouseInformation::~UIMouseInformation() {
    // No realiza ninguna acciòn.
}

