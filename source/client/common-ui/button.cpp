#include "button.h"

Button::Button(UIHandler handler, int x, int y, int width, int height):
    handler(handler),
    x(x),
    y(y),
    width(width),
    height(height) {
    // No realiza ninguna acciòn.
}

bool Button::drawAndProcess(SDL_Surface* mainWindow, UIContext& uiContext) {
    // Obtengo la informaciòn del mouse del contexto de interfaz gràfica.
    ReferenceCountPtr<UIMouseInformation> mouseInformation =
        uiContext.getMouseInformation();

    // Verifico que me encuentro sobre el botòn.
    if (UISupport::isMouseOver(mouseInformation, this->x, this->y, this->width,
        this->height)) {
        // Establezco el botòn como el elemento hot.
        uiContext.setHotItem(handler);
        // Verifico que se presionò.
        if (uiContext.getActiveItem().getElementId() == 0 &&
            mouseInformation->getReleaseStatus() == SDL_PRESSED) {
            // Establezco el botòn como el elemento activo,
            uiContext.setActiveItem(handler);
        }
        // Dibujo el botòn
        UISupport::drawRectangle(mainWindow, this->x+8, this->y+8, this->width,
            this->height, 0);
        // Verifico si el botòn es el elemento hot.
        if (uiContext.getHotItem() == handler) {
            // Verifico si el botòn es el elemento actuvo.
            if (uiContext.getActiveItem() == handler) {
                UISupport::drawRectangle(mainWindow, this->x+2, this->y+2,
                    this->width, this->height, 0xffffff);
             } else {
                UISupport::drawRectangle(mainWindow, this->x, this->y,
                    this->width, this->height, 0xffffff);
            }
        } else {
            UISupport::drawRectangle(mainWindow, this->x, this->y, this->width,
                this->height, 0xaaaaaa);
        }
        if (mouseInformation->getReleaseStatus() == SDL_PRESSED &&
            uiContext.getHotItem() == handler &&
            uiContext.getActiveItem() == handler) {
            return true;
        }
    }
    return false;
}

Button::~Button() {
    // No realiza ninguna acciòn.
}

