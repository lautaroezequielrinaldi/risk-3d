#include "waiting.h"

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

bool Waiting::defend(Defend & command){
	std::cerr << "Evento Waiting::defend" << std::endl;
	return false;
}


bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre" << std::endl;

	// como este mensaje solo puede ser para mi, tomar nota de quien soy
	
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

bool Waiting::kill(Kill & command){
	std::cerr << "Evento Waiting::kill" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::move(Move & command){
	std::cerr << "Evento Waiting::move" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::setOwner(SetOwner & command){
	std::cerr << "Evento Waiting::setOwner" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::lose(Lose & command){
	std::cerr << "Evento Waiting::lose" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::map(Map & command){
	std::cerr << "Evento Waiting::map" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::turnToMove(TurnToMove & command){
	std::cerr << "Evento Waiting::turnToMove" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
bool Waiting::turnToOccupy(TurnToOccupy & command){
	std::cerr << "Evento Waiting::turnToOccupy" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}
