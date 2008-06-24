#include "../../common/net/sockets/socket.h"
#include "../../common/commands/joingame.h"
#include <iostream>

#include<sstream>

#include <SDL.h>
#include "../common-ui/glbutton.h"
int main(int argc, char** argv) {
	// Aca iria el codigo del cliente
	/*
	modo 2d
	ofrece cambiar ip, puerto y conectar

	ServerProxy es el hilo que escucha comandos del servidor
	el loop de GTKmm es el hilo que genera los comandos locales

	si es el primero (el server enviara un ChooseMap con una lista)
		aparecera un menu de seleccion de mapas y un choose

	boton de Ready
	area de chat
	
	*/
/*
	Socket * socket = new Socket("localhost", 2000);

	JoinGame * joinGame = new JoinGame();
	std::string cmd = joinGame->serialize();
	std::cerr << cmd << std::endl;
	std::cerr << cmd.size() << std::endl;

	std::stringstream header;
	header << cmd.size();
	header << " joingame ";

	std::string msg = header.str();
	

	while (msg.size() < 30) {
		msg.append(".");
	}

	msg.append("\r\n");
	msg.append(cmd);

	socket->write(msg);
	std::cerr << msg << std::endl;

	//ServerProxyi*/
	SDL_Surface* screen;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 0;
	}
	screen = SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
	GLButton button(10,10,110,110);

	SDL_Event event;
	bool running = true;
	while(running) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
				case SDL_MOUSEBUTTONDOWN:
					button.processMouseButton(event.button);
				case SDL_MOUSEBUTTONUP:
					button.processMouseButton(event.button);
			}
			button.draw();
			SDL_GL_SwapBuffers();
		}
	}
	SDL_FreeSurface(screen);
}
