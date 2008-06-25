#include "waiting.h"

Waiting::Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Waiting::~Waiting()
{
}

bool Waiting::attack(Attack & command){
	std::cerr << "Evento Waiting::attack" << std::endl;
	return false;
}

bool Waiting::defend(Defend & command){
	std::cerr << "Evento Waiting::defend" << std::endl;
	return false;
}


bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre" << std::endl;
	return false;
}

bool Waiting::turnToAttack(TurnToAttack & command){
	std::cerr << "Evento Waiting::turnToAttack" << std::endl;
	return false;
}


