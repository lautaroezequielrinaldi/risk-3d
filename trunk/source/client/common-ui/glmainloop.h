#ifndef __GLMAINLOOP_H__
#define __GLMAINLOOP_H__

#include<SDL.h> // Para definicion de las funciones de SDL.
#include "glkeymanager.h" // Para definicion de GLKeyManager.
#include "glwidgetmanager.h" // Para definicion de GLWidgetManager.
#include "../../common/smartpointer/referencecountptr.h"

/**
 * Representa el loop principal del juego.
 */
class GLMainLoop {
	/**
	 * Atributos privados de la clase GLMainLoop.
	 */
	private:
		/**
		 * Almacena el estado de ejecucion de la clase GLMainLoop.
		 */
		static bool running;

	/**
	 * Metodos privados de la clase GLMainLoop.
	 */
	private:
		/**
		 * Despacha un evento de mouse presionado.
		 */
		static void dispatchMouseButtonDownEvent(
			const SDL_MouseButtonEvent& event);
		/**
		 * Despacha un evento de mouse liberado.
		 */
		static void dispatchMouseButtonUpEvent(
			const SDL_MouseButtonEvent& event);
		/**
		 * Despacha un evento de movimiento de mouse.
		 */
		static void dispatchMouseMotionEvent(
			const SDL_MouseMotionEvent& event);
		/**
		 * Despacha un evento de tecla presionada.
		 */
		static void dispatchKeyDownEvent(
			const SDL_KeyboardEvent& event);
		/**
		 * Despacha un evento de tecla liberada.
		 */
		static void dispatchKeyUpEvent(
			const SDL_KeyboardEvent& event);
		/**
		 * Hace un update de la escena.
		 */
		static void updateScene();
		/**
		 * Hace un render de la escena.
		 */
		static void renderScene();

	/**
	 * Metodos publicos de la clase GLMainLoop.
	 */
	public:
		/**
		 * Ejecuta el loop principal de eventos y dibujado de widgets.
		 */
		static void run();
		/**
		 * Verifica el estado de ejecucion de la clase GLMainLoop.
		 */
		static bool isRunning();
		/**
		 * Termina la ejecucion del loop principal de eventos y dibujado de
		 * widgets.
		 */
		static void stopRunning();
};

#endif /** __GLMAINLOOP_H__ */
