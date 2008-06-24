#include "client3d.h"
#include<iostream>
Client3D::Client3D():
	button(NULL) {
	std::cout << "A punto de crear widget" << std::endl;
	// Crea el boton.
	this->button = new ButtonWidget(0, 0, 100, 100);
	std::cout << "Widget creado" << std::endl;

	// Registra el boton en el UIManager.
	UIManager::getInstance().addWidget(this->button);
	std::cout << "Agrego el widget al UIManager." << std::endl;
}

int Client3D::run() {
    SDL_Event event;

    while (  true  ) {
        if (  SDL_PollEvent(  &event  )  ) {
            switch (event.type) {
				case SDL_MOUSEBUTTONDOWN:
					button->processMouseButtonEvent(event.button);
				case SDL_MOUSEBUTTONUP:
					button->processMouseButtonEvent(event.button);
			}
        }
		UIManager::getInstance().drawAllWidgets();
	}
}

Client3D::~Client3D() {
}

