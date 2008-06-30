#include "waiting.h"
#include "stateobserver.h"
#include "../commands/uireadytoplay.h"
#include "../commands/readytoplay.h"
#include "../commands/youare.h"

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




bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre" << std::endl;

	// como este mensaje solo puede ser para mi, tomar nota de quien soy
	gameManager->setMe(command.getJugador());
	
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
	parameters.push_back("1");
	//parameters.push_back(gameManager->whoAmI());

	ReadyToPlay * readyToPlay = new ReadyToPlay(parameters);
	this->gameManager->notify(readyToPlay);
	delete(readyToPlay);


	return false;
}

void Waiting::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

