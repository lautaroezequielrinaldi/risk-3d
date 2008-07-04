#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "glhelper.h"
#include "itemhandler.h"
#include "uistate.h"

class Widget {
	/**
	 * Atributos privados de la clase Widget.
	 */
	private:
		/**
		 * Almacena el estado de la UI.
		 */
		UIState& uiState;
		/**
		 * Almacena el Id del widget.
		 */
		int id;
		/**
		 * Almacena la posicion X del widget.
		 */
		float x;
		/**
		 * Almacena la posicion y del widget.
		 */
		float y;
		/**
		 * Almacena el ancho del widget.
		 */
		float width;
		/**
		 * Almacena el alto del widget.
		 */
		float height;
		/**
		 * Almacena el estado visible del widget.
		 */
		bool visible;
		/**
		 * Almacena el estado habilitado del widget.
		 */
		bool enabled;
	/**
	 * Metodos protegidos de la clase Widget.
	 */
	protected:
		/**
		 * Veritica si el mouse esta encima.
		 */
		bool isMouseOver() const;
	/**
	 * Metodos publicos de la clase Widget.
	 */
	public:
		/**
		 * Constructor de la clase Widget.
		 */
		Widget(UIState& uiState, const float& x, const float& y,
			const float& width, const float& height,
			const bool& visible = true, const bool& enabled = true);
		/**
		 * Establece el estado UI de la clase Widget.
		 */
		void setUIState(const UIState& uiState);
		/**
		 * Obtiene el estado UI de la clase Widget.
		 */
		UIState& getUIState() const;
		/**
		 * Establece el Id del widget.
		 */
		int getId() const;
		/**
		 * Establece la posicion Y del widget.
		 */
		void setX(const float& x);
		/**
		 * Obtiene la posicion X del widget.
		 */
		float getX() const;
		/**
		 * Establece la posicion Y del widget.
		 */
		void setY(const float& y);
		/**
		 * Obtiene la posicion Y del widget.
		 */
		float getY() const;
		/**
		 * Establece el ancho del widget.
		 */
		void setWidth(const float& width);
		/**
		 * Obtiene el ancho del widget.
		 */
		float getWidth() const;
		/**
		 * Establece el alto del widtet.
		 */
		void setHeight(const float& height);
		/**
		 * Obtiene el alto del widget.
		 */
		float getHeight() const;
		/**
		 * Establece el estado visible del widget.
		 */
		void setVisible(const bool& visible);
		/**
		 * Obtiene el estado visible del widget.
		 */
		bool getVisible() const;
		/**
		 * Establece el estado habilitado del widget.
		 */
		void setEnabled(const bool& enabled);
		/**
		 * Obtiene el estado habilitado del widget.
		 */
		bool getEnabled() const;
		/**
		 * Metodo virtual puro que dibuja el widget e indica si se ha\
		 * presionado o no.
		 */
		virtual bool doProcess() = 0;
		/**
		 * Destructor virtual de la clase Widget.
		 */
		virtual ~Widget();
};

#endif /** __WIDGET_H__ */

