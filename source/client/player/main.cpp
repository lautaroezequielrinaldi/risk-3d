#include "../../common/commands/joingame.h"

#include "../../common/model/randomdice.h"
#include "../../common/model/gamemanager.h"
#include "../../common/model/game.h"
#include "../../common/model/turnmanager.h"
#include "../../common/serverproxy.h"

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

	Dice *dado = new RandomDice();
	std::cerr<< "Dice created" << std::endl;

	ReferenceCountPtr<Game>        game       = new Game(*dado);
	std::cerr<< "Game created" << std::endl;

	ReferenceCountPtr<TurnManager> turnmanager= new TurnManager();
	std::cerr<< "TurnManager created" << std::endl;

	ReferenceCountPtr<GameManager> gamemanager= new GameManager(game,turnmanager);
	std::cerr<< "GameManager created" << std::endl;

	Socket * socket = new Socket("localhost", 2000);

	ReferenceCountPtr<ServerProxy> serverProxy= new ServerProxy(socket, gamemanager);
	std::cerr<< "ServerProxy created" << std::endl;

	 gamemanager->add(serverProxy);


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

	std::cerr << "Escribiendo..." << std::endl;
	serverProxy->notify(msg);
	std::cerr << "Escrito..." << std::endl;

	std::cerr << msg << std::endl;

	serverProxy->start();
	//ServerProxy

if (false) {
	SDL_Surface* screen;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 0;
	}
	screen = SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
	GLButton button("Primer Boton!!!");

	SDL_Event event;
	bool running = true;
	while(running) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					break;
					//button.processMouseButton(event.button);
				case SDL_MOUSEBUTTONUP:
					break;
					//button.processMouseButton(event.button);
			}
			button.draw();
			SDL_GL_SwapBuffers();
		}
	}
	SDL_FreeSurface(screen);
}
}
