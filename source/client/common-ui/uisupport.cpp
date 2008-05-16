#include "uisupport.h"

bool UISupport::isMouseOver(
        ReferenceCountPtr<UIMouseInformation> mouseInformation, int x, int y,
        int width, int height) {
    if ( (((int) mouseInformation->getX()) < x) ||
         (((int) mouseInformation->getY()) < y) ||
         (((int) mouseInformation->getX()) >= x + width) ||
         (((int) mouseInformation->getY()) >= y + height) )
        return false;
    return true;
}

void UISupport::drawRectangle(SDL_Surface* surface, int x, int y, int width,
        int height, int color) {
    SDL_Rect r;
        r.x = x;
        r.y = y;
        r.w = width;
        r.h = height;
    SDL_FillRect(surface, &r, color);
}

