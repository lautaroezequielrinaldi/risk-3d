#include "serverturntoattack.h"

ServerTurnToAttack::ServerTurnToAttack(): ServerCommand(), TurnToAttack()
{
}

ServerTurnToAttack::ServerTurnToAttack(const std::string & xml): ServerCommand(), TurnToAttack(xml)
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


