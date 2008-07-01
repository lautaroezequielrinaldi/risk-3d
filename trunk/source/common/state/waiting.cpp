#include "waiting.h"
#include "stateobserver.h"



#include "../commands/uireadytoplay.h"
#include "../commands/readytoplay.h"
#include "../commands/uiquit.h"
#include "../commands/quit.h"
#include "../commands/uinomore.h"
#include "../commands/nomore.h"
#include "../commands/uisurrender.h"
#include "../commands/surrender.h"
#include "../commands/uididiwin.h"
#include "../commands/didiwin.h"
#include "../commands/selectmap.h"
#include "../commands/uiselectmap.h"

#include "../commands/youare.h"

#include <sstream>

Waiting::Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Waiting::~Waiting()
{
}

bool Waiting::attack(Attack & command){
	std::cerr << "Evento Waiting::attack" << std::endl;
	/*

	 if (isForMe()) {
		// pasar a modo Defending

	}
	

	*/
	return false;
}

bool Waiting::mapList(MapList & command){
	
	std::cerr << "Evento Waiting::mapList" << std::endl;
	/* Debe hace aparecer un dialogo en la presala
	 *
	 *
	 */

	return false;
}


bool Waiting::quit(Quit & command) {
	std::cerr << "Evento Waiting::Quit" << std::endl;
	// si es valido
	if (command.getFrom() == gameManager->getMe()) {
		// cerrar la aplicacion de un modo mas elegante...
		throw 20;
	} else {
		// notificar a la interfaz que el usuario tal se fue del juego
	}
	return false;
}

bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre : " << command.getTo() << std::endl;
	gameManager->setMe(command.getTo());
	
	return false;
}

bool Waiting::turnToAttack(TurnToAttack & command){
	std::cerr << "Evento Waiting::turnToAttack" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}


bool Waiting::move(Move & command){
	std::cerr << "Evento Waiting::move" << std::endl;

	return false;
}

bool Waiting::lose(Lose & command){
	std::cerr << "Evento Waiting::lose" << std::endl;

	
	//if (isForMe()) {
		//pasar a modo Observing, no implementado aun
	//}
	
	return false;
}
bool Waiting::map(Map & command){
	std::cerr << "Evento Waiting::map" << std::endl;

	return false;
}
bool Waiting::turnToMove(TurnToMove & command){
	std::cerr << "Evento Waiting::turnToMove" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Moving
	}
	*/
	return false;
}
bool Waiting::turnToOccupy(TurnToOccupy & command){
	std::cerr << "Evento Waiting::turnToOccupy" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Occupying
	}
	*/
	return false;
}

bool Waiting::uiReadyToPlay(UIReadyToPlay & command){
	ReadyToPlay * cmd = new ReadyToPlay();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiQuit(UIQuit & command){
	std::cerr << "Evento Waiting::uiQuit from: "<< gameManager->getMe() << std::endl;

	Quit * cmd = new Quit();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiNoMore(UINoMore & command){
	std::cerr << "Evento Waiting::uiNoMore" << std::endl;

	NoMore * cmd = new NoMore();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiSurrender(UISurrender & command){
	Surrender * cmd = new Surrender();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiDidIWin(UIDidIWin & command){
	DidIWin * cmd = new DidIWin();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;

}

bool Waiting::uiSelectMap(UISelectMap & command){
	std::cerr << "Waiting::uiSelectMap me: " << gameManager->getMe() << std::endl;

	SelectMap * cmd = new SelectMap();
	cmd->setFrom(gameManager->getMe());
	cmd->setMapName(command.getMapName());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;


}
void Waiting::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

