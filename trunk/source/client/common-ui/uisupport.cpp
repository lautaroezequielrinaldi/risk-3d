#include "uisupport.h"

bool UISupport::isMouseOver(const UIMouseInformation& mouseInformation, int x,
    int y, int width, int height) {
    if ( (((int) mouseInformation.getX()) < x) ||
         (((int) mouseInformation.getY()) < y) ||
         (((int) mouseInformation.getX()) >= x + width) ||
         (((int) mouseInformation.getY()) >= y + height) )
        return false;
    return true;
}

