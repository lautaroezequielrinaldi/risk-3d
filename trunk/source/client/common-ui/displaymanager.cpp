#include "displaymanager.h"
#include<iostream>
DisplayManager::DisplayManager():
	screen(NULL) {
	// Inicihaliza el modo de video SDL.
	if ( SDL_Init(SDL_INIT_VIDEO) >= 0 ) {
		// Creo la superficie SDL que representa la pantalla del juego.
		this->screen = SDL_SetVideoMode(MAX_WIDTH_RESOLUTION,
			MAX_HEIGHT_RESOLUTION, MAX_COLOR_DEPTH, SDL_OPENGL
			| SDL_RESIZABLE | SDL_HWSURFACE );
	}
}

void DisplayManager::drawRectangle(int x, int y, int width, int height,
	int color) {
	std::cout << "Entrando a drawRectangle" << std::endl;
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = width;
	rectangle.h = height;
	if (screen == NULL) {
		std::cout << "Screen es NULL" << std::endl;
	}
	SDL_FillRect(this->screen, &rectangle, color);
	std::cout << "Saliendo de drawRectangle" << std::endl;
}

void DisplayManager::updateScreen() {
	SDL_UpdateRect(this->screen, 0, 0, MAX_WIDTH_RESOLUTION,
		MAX_HEIGHT_RESOLUTION);
	SDL_Flip(this->screen);
	SDL_GL_SwapBuffers();
}

DisplayManager::~DisplayManager() {
	if (this->screen != NULL) {
		SDL_FreeSurface(this->screen);
	}
}

