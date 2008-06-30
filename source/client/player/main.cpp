#include "../../common/commands/joingame.h"

#include "../../common/commands/uireadytoplay.h"
#include "../../common/commands/uiquit.h"
#include "../../common/commands/uisurrender.h"
#include "../../common/commands/uinomore.h"
#include "../../common/commands/uididiwin.h"
#include "../../common/commands/uiselectmap.h"



#include "../../common/model/randomdice.h"
#include "../../common/model/gamemanager.h"
#include "../../common/model/game.h"
#include "../../common/model/turnmanager.h"
#include "../../common/serverproxy.h"
#include "../../common/state/clientstatemachine.h"

#include <iostream>

#include <sstream>
#include<gtkmm/main.h>
#include "pregamewindow.h"

#include <GL/glut.h>
#include "../common-ui/glwidgetmanager.h"
#include "../common-ui/glmainloop.h"
#include "../common-ui/glbutton.h"
#include "../common-ui/gllabel.h"
#include "../common-ui/glspherewidget.h"
#include "../common-ui/mouseobserver.h"
#include "../../common/smartpointer/referencecountptr.h"

class UIObserver: public MouseObserver {
	public:
		UIObserver(){};
		virtual ~UIObserver(){};

		void setGameManager(ReferenceCountPtr<GameManager> gamemanager) {
			this->gamemanager = gamemanager;
		}
	protected:
		ReferenceCountPtr<GameManager> gamemanager;
};


class ReadyToPlayOnClickObserver: public UIObserver {
	public:
		void mousePressed(const SDL_MouseButtonEvent& event) {
			gamemanager->execute(new UIReadyToPlay());
		}
};

class QuitOnClickObserver: public UIObserver {
	public:
		void mousePressed(const SDL_MouseButtonEvent& event) {
			gamemanager->execute(new UIQuit());
		}
};

class SurrenderOnClickObserver: public UIObserver {
	public:
		void mousePressed(const SDL_MouseButtonEvent& event) {
			gamemanager->execute(new UISurrender());
		}
};

class NoMoreOnClickObserver: public UIObserver {
	public:
		void mousePressed(const SDL_MouseButtonEvent& event) {
			gamemanager->execute(new UINoMore());
		}
};

class DidIWinOnClickObserver: public UIObserver {
	public:
		void mousePressed(const SDL_MouseButtonEvent& event) {
			gamemanager->execute(new UIDidIWin());
		}
};


class SelectMapOnClickObserver: public UIObserver {
    public:
        void mousePressed(const SDL_MouseButtonEvent& event) {
		std::vector<std::string> parameters;
	
		parameters.push_back("0");
		parameters.push_back("mapa 1"); // seleccion hardcodeada de mapa
		std::cerr << "SelectMapOnClickObserver::mousePressed" << std::endl;
		gamemanager->execute(new UISelectMap(parameters));
        }
};






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
	Gtk::Main main(argc, argv);

if (false) {
	PreGameWindow preGameWindow(gamemanager);
	Gtk::Main::run(preGameWindow);

} else {
	Socket * socket = new Socket("localhost", 2000);
	std::cerr<< "Socket created" << std::endl;

	// que pasa si ...
	// serverProxy= new ServerProxy(new Socket("localhost", 2000), gamemanager); ?

	ReferenceCountPtr<ServerProxy> serverProxy= new ServerProxy(socket, gamemanager);
	std::cerr<< "ServerProxy created" << std::endl;

	gamemanager->add(serverProxy);

	serverProxy->notify(new JoinGame());

	serverProxy->start();
	
//	serverProxy->cancel();
//	std::cerr << "Canceled" << std::endl;

	// va a quedar bloqueado aca hasta que reciba un mensaje via socket
	// para desbloquearse del read()
	//serverProxy->join();
	//std::cerr << "Joined" << std::endl;
	while (false && !serverProxy->isCanceled()) {
		sleep(10);
		std::cerr << "looping" << std::endl;
	}
}

	glutInit(&argc, argv);
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 0;
	}
	SDL_Surface* screen = SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL);

	
	SelectMapOnClickObserver selectMapOnClickObserver; 
	selectMapOnClickObserver.setGameManager(gamemanager);

	
	ReadyToPlayOnClickObserver readyToPlayOnClickObserver; 
	readyToPlayOnClickObserver.setGameManager(gamemanager);

	QuitOnClickObserver quitOnClickObserver;
	quitOnClickObserver.setGameManager(gamemanager);

	NoMoreOnClickObserver noMoreOnClickObserver;
	noMoreOnClickObserver.setGameManager(gamemanager);

	SurrenderOnClickObserver surrenderOnClickObserver;
	surrenderOnClickObserver.setGameManager(gamemanager);

	DidIWinOnClickObserver didIWinOnClickObserver;
	didIWinOnClickObserver.setGameManager(gamemanager);

	
	ReferenceCountPtr<GLButton> readyToPlayButton( new GLButton("ReadyToPlay"));
	readyToPlayButton->setX(600);
	readyToPlayButton->setY(0);
	readyToPlayButton->addMouseObserver(&readyToPlayOnClickObserver);


	ReferenceCountPtr<GLButton> quitButton( new GLButton("Quit"));
	quitButton->setX(600);
	quitButton->setY(40);
	quitButton->addMouseObserver(&quitOnClickObserver);

	ReferenceCountPtr<GLButton> surrenderButton( new GLButton("Surrender"));
	surrenderButton->setX(600);
	surrenderButton->setY(80);
	surrenderButton->addMouseObserver(&surrenderOnClickObserver);

	ReferenceCountPtr<GLButton> noMoreButton( new GLButton("NoMore"));
	noMoreButton->setX(600);
	noMoreButton->setY(120);
	noMoreButton->addMouseObserver(&noMoreOnClickObserver);

	ReferenceCountPtr<GLButton> didIWinButton( new GLButton("DidIWin"));
	didIWinButton->setX(600);
	didIWinButton->setY(160);
	didIWinButton->addMouseObserver(&didIWinOnClickObserver);

	ReferenceCountPtr<GLButton> selectMapButton( new GLButton("Seleccionar mapa 1"));
	selectMapButton->setX(600);
	selectMapButton->setY(190);
	selectMapButton->addMouseObserver(&selectMapOnClickObserver);
	
	
	ReferenceCountPtr<GLLabel> label( new GLLabel("Esto es un label muy largo largo largo Label!!!"));
	label->setX(10);
	label->setY(280);
	ReferenceCountPtr<GLSphereWidget> sphere(new GLSphereWidget("mapa.jpg", 0.3));
	
	GLWidgetManager::register2DWidget(readyToPlayButton);


	GLWidgetManager::register2DWidget(quitButton);
	GLWidgetManager::register2DWidget(surrenderButton);
	GLWidgetManager::register2DWidget(noMoreButton);
	GLWidgetManager::register2DWidget(didIWinButton);
	GLWidgetManager::register2DWidget(selectMapButton);

	GLWidgetManager::register2DWidget(label);
	GLWidgetManager::register3DWidget(sphere);
	GLMainLoop::run();
	
	SDL_FreeSurface(screen);

}
