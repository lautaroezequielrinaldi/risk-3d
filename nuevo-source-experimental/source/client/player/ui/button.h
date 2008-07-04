#ifndef __BUTTON_H__
#define __BUTTON_H__

#include<string>
#include "widget.h"

class Button: public Widget {
	/**
	 * Atributos privados de la clase Button.
	 */
	private:
		/**
		 * Texto del boton.
		 */
		std::string text;
	/**
	 * Metodos publicos de la clase Button.
	 */
	public:
		/**
		 * Constructor de la clase Button.
		 */
		Button(UIState& uiState);
		/**
		 * Constructor de la clase Button.
		 */
		Button(UIState& uiState, const std::string& text, const float& x,
		const float& y, const float& width, const float& height,
		const bool& visible = true, const bool& enabled = true);
		/**
		 * Establece el texto del boton.
		 */
		void setText(const std::string& text);
		/**
		 * Obtiene el texto del boton.
		 */
		std::string getText() const;
		/**
		 * Procesa el widget.
		 */
		virtual bool doProcess();
		/**
		 * Destructor virtual de la clase Button.
		 */
		virtual ~Button();
};

#endif /** __BUTTON_H__ */

