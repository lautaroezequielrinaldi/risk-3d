#ifndef __LABEL_H__
#define __LABEL_H__

#include<string>
#include "widget.h"

class Label: public Widget {
	/**
	 * Atributos privados de la clase Label.
	 */
	private:
		/**
		 * Almacena el texto del label.
		 */
		std::string text;
	/**
	 * Metodos publicos de la clase Label.
	 */
	public:
		/**
		 * Constructor de la clase Label.
		 */
		Label(UIState& uiState);
		/**
		 * Constructor de la clase Label.
		 */
		Label(UIState& uiState, const std::string& text, const float& x,
		const float& y, const float& width, const float& height,
		const bool& visible = true, const bool& enabled = true);
		/**
		 * Procesa el widget.
		 */
		virtual bool doProcess();
		/**
		 * Obtiene el texto del label.
		 */
		std::string getText() const;
		/**
		 * Destructor virtual de la clase Label.
		 */
		virtual ~Label();
};

#endif /** __LABEL_H__ */

