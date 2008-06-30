#ifndef __GLKEYMANAGER_H__
#define __GLKEYMANAGER_H__

#include<SDL.h>

class GLKeyManager {
	/**
	 * Atributos privados de la clase GLKeyManager.
	 */
	private:
		/**
		 * Almacena el vector de teclas de SDL.
		 */
		static bool keyboard[SDLK_LAST];
	/**
	 * Metodos publicos de la clase GLKeyManager.
	 */
	public:
		/**
		 * Presiona una tecla.
		 */
		static void pressKey(const SDLKey& key);
		/**
		 * Libera una tecla.
		 */
		static void releaseKey(const SDLKey& key);
		/**
		 * Verifica si una tecla esta presionada.
		 */
		static bool isKeyPressed(const SDLKey& key);
};

#endif /** __GLKEYMANAGER_H__ */

