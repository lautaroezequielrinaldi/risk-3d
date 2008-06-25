#ifndef __GLBUTTON_H__
#define __GLBUTTON_H__

#include<string> // Para definicion de std::string.
#include "gl2dwidget.h"
#include "gldrawhelper.h"

class GLButton: public GL2DWidget {
	/**
	 * Atributos privados de la clase GLButton.
	 */
	private:
		/**
		 * Almacena el texto del boton.
		 */
		std::string text;
	/**
	 * Metodos protegidos de la clase GLButton.
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
		 * Constructor de la clase GLButton.
		 */
		GLButton(const std::string& text);
		/**
		 * Constructor de la clase GLButton.
		 */
		GLButton(const Dimension& dimension, const bool& visble = true, const bool& enabled = true,
				const std::string& text = "");
		/**
		 * Obtiene el texto del boton.
		 */
		std::string getText();
		/**
		 * Establece el texto del boton.
		 */
		void setText(const std::string& text);
		/**
		 * Destructor virtual de la clase GLButton.
		 */
		virtual ~GLButton();
};

#endif /** __GLBUTTON_H__ */

