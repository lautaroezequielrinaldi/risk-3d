#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "widget.h"

class Button: public Widget {
	/**
	 * Metodos publicos de la clase Button.
	 */
	public:
		/**
		 * Constructor de la clase Button.
		 */
		Button(UIState& uiState, const float& x, const float& y,
		const float& width, const float& height, const bool& visible = false,
		const bool& enabled = false);
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

