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

	std::cerr << "Evento Waiting::attack" << std::endl;
	return false;
}


bool Waiting::quit(Quit & command) {
	std::cerr << "Evento Waiting::Quit" << std::endl;
	return false;
}

bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre : " << command.getTo() << std::endl;

	// como este mensaje solo puede ser para mi, tomar nota de quien soy
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
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	this->gameManager->notify(new ReadyToPlay(parameters));
	return false;
}

bool Waiting::uiQuit(UIQuit & command){
	std::cerr << "Evento Waiting::uiQuit" << std::endl;
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	this->gameManager->notify(new Quit(parameters));
	return false;
}

bool Waiting::uiNoMore(UINoMore & command){
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	this->gameManager->notify(new NoMore(parameters));
	return false;
}

bool Waiting::uiSurrender(UISurrender & command){
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	this->gameManager->notify(new Surrender(parameters));
	return false;
}

bool Waiting::uiDidIWin(UIDidIWin & command){
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	this->gameManager->notify(new DidIWin(parameters));
	return false;
}

bool Waiting::uiSelectMap(UISelectMap & command){
	std::vector<std::string> parameters;
	std::ostringstream strMe;
	strMe << gameManager->getMe();
	parameters.push_back(strMe.str());
	std::cerr << "Waiting::uiSelectMap me: " << gameManager->getMe() << std::endl;
	parameters.push_back(command.getMapName());
	this->gameManager->notify(new SelectMap(parameters));
	return false;
}
void Waiting::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

