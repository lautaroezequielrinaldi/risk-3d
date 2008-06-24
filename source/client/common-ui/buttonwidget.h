#ifndef __BUTTONWIDGET_H__
#define __BUTTONWIDGET_H__

#include "glwidget.h"
#include "uimanager.h"
#include "displaymanager.h"

/**
 * Clase que representa un boton GLWidget al cual se le puede hacer click.
 */
class ButtonWidget: public GLWidget {
	/**
	 * Metodos publicos de la clase ButtonWidget.
	 */
	public:
	    /**
		 * Constructor de la clase ButtonWidget.
		 */
        ButtonWidget(const int& x, const int& y, const int& width,
            const int& height, const bool& visible = true,
            const bool& enabled = true);
		/**
		 * Dibuja el widget en pantalla.
		 */
		virtual void draw();
		/**
		 * Destructor virtual de la clase ButtonWidget.
		 */
		virtual ~ButtonWidget();
};

#endif /** __BUTTONWIDGET_H__ */

