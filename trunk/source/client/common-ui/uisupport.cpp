#include "uisupport.h"

bool UISupport::isMouseOver(const UIMouseInformation& mouseInformation, int x,
    int y, int width, int height) {
    if ( (mouseInformation.getX() < x) ||
         (mouseInformation.getY() < y) ||
         (mouseInformation.getX() >= x + width) ||
         (mouseInformation.getY() >= y + height) )
        return false;
    return true;
}

