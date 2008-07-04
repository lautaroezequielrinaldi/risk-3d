#ifndef __UISTATE_H__
#define __UISTATE_H__

#include "itemhandler.h"

class UIState {
	/**
	 * Atributos privados de la clase UIState.
	 */
	private:
		/**
		 * Almacena el active item en la user interface.
		 */
		int activeItem;
		/**
		 * Almacena el hot item en la user interface.
		 */
		int hotItem;
		/**
		 * Almacena la ultima posicion X del boton.
		 */
		int mouseX;
		/**
		 * Almacena la ultima posicion Y del boton.
		 */
		int mouseY;
		/**
		 * Almacena el estado de presion del boton.
		 */
		bool mousePressed;

	/**
	 * Metodos publicos de la clase UIState.
	 */
	public:
		/**
		 * Constructor de la clase UIState.
		 */
		UIState();
		/**
		 * Initializes the UIState.
		 */
		void prepare();
		/**
		 * Terminates the UIState.
		 */
		void unprepare();
		/**
		 * Establece el active item de la user interface.
		 */
		void setActiveItem(const int& activeItem);
		/**
		 * Obtiene el active item de la user interface.
		 */
		int getActiveItem() const;
		/**
		 * Establece el hot item de la user interface.
		 */
		void setHotItem(const int& hotItem);
		/**
		 * Obtiene el hot item de la user interface.
		 */
		int getHotItem() const;
		/**
		 * Establece la ultima posicion X del mouse.
		 */
		void setMouseX(const int& x);
		/**
		 * Obtiene la ultima posicion X del mouse.
		 */
		int getMouseX() const;
		/**
		 * Establece la ultima posicion Y del mouse.
		 */
		void setMouseY(const int& y);
		/**
		 * Obtiene la ultima posicion Y del mouse.
		 */
		int getMouseY() const;
		/**
		 * Establece el estado de presion de mouse.
		 */
		void setMousePressed(const bool& mousePressed);
		/**
		 * Establece el estado de presion de mouse.
		 */
		int getMousePressed() const;
		/**
		 * Destructor virtual de la clase UIState.
		 */
		virtual ~UIState();
};

#endif /** __UISTATE_H__ */

