#ifndef __GLBUTTON_H__
#define __GLBUTTON_H__

#include "glwidget.h"

/**
 * Clase que encapsula un boton 2D a travez de OpenGL.
 */
class GLButton: public GLWidget {
	/**
	 * Metodos protegidos de la clase GLButton.
	 */
	protected:
		/**
		 * Se invoca al dibujar el componente.
		 */
		virtual void drawWidget();
	/**
	 * Metodos publicos de la clase GLButton.
	 */
	public:
        /**
         * Constructor de la clase GLButton.
         */
        GLButton(const int& x = 0, const int& y = 0, const int& width = 0,
            const int& height = 0, const bool& visible = true,
            const bool& enabled = true, const bool& hoover = false);
        /**
         * Procesa un evento de boton de mouse en caso de que sea para el.
         */
        virtual void processMouseButton(const SDL_MouseButtonEvent& event);
        /**
         * Procesa un evento de movimiento de mouse en caso de que sea para el.
         */
        virtual void  processMouseMotion(
            const SDL_MouseMotionEvent& event);
        /**
         * Procesa un evento de teclado en caso de que sea para el.
         */
        virtual void processKeyboard(const SDL_KeyboardEvent& event);
        /**
         * Destructor virtual de la clase GLWidget.
         */
        virtual ~GLButton();
};

#endif /** __GLBUTTON_H__ */

