#include "../../common/commands/joingame.h"
#include "../../common/commands/readytoplay.h"

#include "../../common/model/randomdice.h"
#include "../../common/model/gamemanager.h"
#include "../../common/model/game.h"
#include "../../common/model/turnmanager.h"
#include "../../common/serverproxy.h"
#include "../../common/state/clientstatemachine.h"

#include <iostream>

#include<sstream>
#include <GL/glut.h>
#include "../common-ui/glwidgetmanager.h"
#include "../common-ui/glmainloop.h"
#include "../common-ui/glbutton.h"
#include "../common-ui/gllabel.h"
#include "../common-ui/glspherewidget.h"
#include "../common-ui/mouseobserver.h"
#include "../../common/smartpointer/referencecountptr.h"

class SimpleMouseObserver: public MouseObserver {
	/**
	 * Metodos publicos:
	 */
	public:
		/**
		 * Mouse Pressed.
		 */
		void mousePressed(const SDL_MouseButtonEvent& event) {
			std::cout << "Se presiono el mouse en X: " << event.x << " y en Y: " << event.y << std::endl;
			
			ReadyToPlay * readyToPlay = new ReadyToPlay();

			gamemanager->notify(readyToPlay);
			delete(readyToPlay);

		}

		void setGameManager(ReferenceCountPtr<GameManager> gamemanager) {
			this->gamemanager = gamemanager;
		}

	private:
		ReferenceCountPtr<GameManager> gamemanager;
};

int main1(int argc, char** argv) {

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

	// aca no deberiamos necesitar el Dice, corregir

	Dice *dado = new RandomDice();
	std::cerr<< "unnecessary Dice created" << std::endl;

	ReferenceCountPtr<Game>        game       = new Game(*dado);
	std::cerr<< "Game created" << std::endl;

	// aca no deberiamos necesitar el TurnManager, corregir

	ReferenceCountPtr<TurnManager> turnmanager= new TurnManager();
	std::cerr<< "unnecessary TurnManager created" << std::endl;

	ReferenceCountPtr<GameManager> gamemanager= new GameManager(game,turnmanager);
	std::cerr<< "GameManager created" << std::endl;

	ReferenceCountPtr<StateMachine> stateMachine = new ClientStateMachine(gamemanager);
	std::cerr<< "StateMachine created" << std::endl;

	stateMachine->setState("waiting");
	std::cerr<< "StateMachine initialized" << std::endl;

	gamemanager->setStateMachine(stateMachine);
	std::cerr<< "StateMachine asigned" << std::endl;

	Socket * socket = new Socket("localhost", 2000);
	std::cerr<< "Socket created" << std::endl;

	ReferenceCountPtr<ServerProxy> serverProxy= new ServerProxy(socket, gamemanager);
	std::cerr<< "ServerProxy created" << std::endl;

	gamemanager->add(serverProxy);

	JoinGame * joinGame = new JoinGame();

	serverProxy->notify(joinGame);
	delete joinGame;
	std::cerr << "Escrito..." << std::endl;

	serverProxy->start();


	
//	serverProxy->cancel();
//	std::cerr << "Canceled" << std::endl;

	// va a quedar bloqueado aca hasta que reciba un mensaje via socket
	// para desbloquearse del read()
	//serverProxy->join();
	//std::cerr << "Joined" << std::endl;


if (true) {
    glutInit(&argc, argv);
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return 0;
    }
    SDL_Surface* screen = SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);
    SimpleMouseObserver observer;

    observer.setGameManager(gamemanager);

    ReferenceCountPtr<GLButton> button( new GLButton("ReadyToPlay"));
    button->setX(20);
    button->setY(20);
    button->addMouseObserver(&observer);

    ReferenceCountPtr<GLButton> button2( new GLButton("Boton2!!!"));
    button2->setX(70);
    button2->setY(70);
    //button2->setEnabled(false);
    button2->addMouseObserver(&observer);

    ReferenceCountPtr<GLLabel> label( new GLLabel("Esto es un label muy largo largo largo Label!!!"));
    label->setX(120);
    label->setY(120);
    ReferenceCountPtr<GLSphereWidget> sphere(new GLSphereWidget(0.3));

    GLWidgetManager::register2DWidget(button);
    GLWidgetManager::register2DWidget(button2);
    GLWidgetManager::register2DWidget(label);
    GLWidgetManager::register3DWidget(sphere);
    GLMainLoop::run();

    SDL_FreeSurface(screen);
}
}
