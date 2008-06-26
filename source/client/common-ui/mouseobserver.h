#ifndef __MOUSEOBSERVER_H__
#define __MOUSEOBSERVER_H__

#include<SDL.h> // Para definicion de funciones SDL.

class MouseObserver {
	/**
	 * Metodos protegidos de la clase MouseObserver.
	 */
	protected:
		/**
		 * Constructor de la clase MouseObserver.
		 */
		MouseObserver();

	/**
	 * Metodos publicos de la clase MouseObserver.
	 */
	public:
		/**
		 * Procesa un evento de presion de mouse.
		 */
		virtual void mousePressed(const SDL_MouseButtonEvent& event);
		/**
		 * Procesa un evento de liberacion de mouse.
		 */
		virtual void mouseReleased(const SDL_MouseButtonEvent& event);
		/**
		 * Procesa un evento de movimiento de mouse.
		 */
		virtual void mouseMoved(const SDL_MouseMotionEvent& event);
		/**
		 * Destructor virtual de la clase MouseObserver.
		 */
		virtual ~MouseObserver();

};

#endif /** __MOUSEOBSERVER_H__ */

