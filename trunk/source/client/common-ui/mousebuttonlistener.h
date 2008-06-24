#ifndef __MOUSEBUTTONLISTENER_H__
#define __MOUSEBUTTONLISTENER_H__

#include <SDL.h> // Para definicino de SDL.

/**
 * Interfaz que debera implementarse para escucuchar notificaciones de
 * eventos Mouse Button de SDL sobre un GLWidget.
 */
class MouseButtonListener { 
	/**
	 * Metodos publicos de la clase MouseButtonListener.
	 */
	public:
		/**
		 * Procesa un evento de Mouse Button SDL.
		 */
		virtual void mouseButtonEventFired(
			const SDL_MouseButtonEvent& event) = 0;
};

#endif /** __MOUSEBUTTONLISTENER_H__ */

