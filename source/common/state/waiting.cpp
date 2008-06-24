#include "waiting.h"

Waiting::Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Waiting::~Waiting()
{
}

bool Waiting::attack(Attack & command){
	return false;
}

bool Waiting::defend(Defend & command){
	return false;
}


bool Waiting::youAre(YouAre & command){
	return false;
}

/*bool Waiting::turnToAttack(turnToAttack & command){
	return false;
}

bool Waiting::battleResult(BattleResult & command){
	return false;
}
*/

