#ifndef __GLLABEL_H__
#define __GLLABEL_H__

#include<string> // Para definicion de std::string.
#include "gl2dwidget.h"
#include "gldrawhelper.h"

class GLLabel: public GL2DWidget {
	/**
	 * Atributos privados de la clase GLLabel.
	 */
	private:
		/**
		 * Almacena el texto del label.
		 */
		std::string text;

	/**
	 * Metodos protegidos de la clase GLLabel.
	 */
	protected:
		/**
		 * Dibuja el widget.
		 */
		virtual void drawWidget();

    /**
	 * Metodos publicos de la clase GLButton.
	 */
    public:
        /**
		 * Constructor de la clase GLLabel.
		 */
        GLLabel(const std::string& text);
        /**
		 * Obtiene el texto del label.
		 */
        std::string getText();
        /**
		 * Establece el texto del boton.
		 */
        void setText(const std::string& text);
        /**
		 * Destructor virtual de la clase GLLabel.
		 */
        virtual ~GLLabel();
};


#endif /** __GLLABEL_H__ */

