#ifndef __LABEL_H__
#define __LABEL_H__

#include "widget.h"

class Label: public Widget {
	/**
	 * Metodos publicos de la clase Label.
	 */
	public:
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
		 * Destructor virtual de la clase Label.
		 */
		virtual ~Label();
};

#endif /** __LABEL_H__ */

