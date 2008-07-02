#include "serverturntoattack.h"

ServerTurnToAttack::ServerTurnToAttack()
{
}

ServerTurnToAttack::~ServerTurnToAttack()
{
}

bool ServerTurnToAttack::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerTurnToAttack::execute(ReferenceCountPtr<State>& state){
	
	state->turnToAttack(*this);
	
}


