#ifndef __DISPLAYMANAGER_H__
#define __DISPLAYMANAGER_H__

#include<SDL.h>

class DisplayManager {
	/**
	 * Atributos privados de la clase DisplayManager.
	 */
	private:
		/**
		 * Almacena la maxima resolucion de la pantalla.
		 */
		static const int MAX_WIDTH_RESOLUTION = 1024;
		/**
		 * Almacena la maxima resolucion de la pantalla.
		 */
		static const int MAX_HEIGHT_RESOLUTION = 768;
		/**
		 * Almacena la maxima profundidad de color de la pantalla.
		 */
		static const int MAX_COLOR_DEPTH = 32;
		/**
		 * Almacena la superficie SDL que representa la pantalla del juego.
		 */
		SDL_Surface* screen;

	/**
	 * Metodos privados de la clase DisplayManager.
	 */
	private:
		/**
		 * Constructor copia de la clase DisplayManager.
		 */
		DisplayManager(const DisplayManager& otherInstance);
		/**
		 * Operador de asignacion de la clase DisplayManager.
		 */
		DisplayManager& operator=(const DisplayManager& otherInstance);

	/**
	 * Metodos publicos de la clase DisplayManager.
	 */
	public:
		/**
		 * Constructor de la clase DisplayManager.
		 */
		DisplayManager();
		/**
		 * Dibuja un rectangulo en la pantalla con el color pasado
		 * como argumento.
		 */
		void drawRectangle(int x, int y, int width, int height, int color);
		/**
		 * Actualiza la pantalla.
		 */
		void updateScreen();
		/**
		 * Destructor virtual de la clase DisplayManager.
		 */
		virtual ~DisplayManager();
};

#endif /** __DISPLAYMANAGER_H__ */

