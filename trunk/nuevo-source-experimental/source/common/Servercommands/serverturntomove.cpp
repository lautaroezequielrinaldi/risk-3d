#include "serverturntomove.h"

ServerTurnToMove::ServerTurnToMove(): ServerCommand(), TurnToMove()
{
}

ServerTurnToMove::ServerTurnToMove(const std::string & xml): ServerCommand(), TurnToMove(xml)
{
}


ServerTurnToMove::~ServerTurnToMove()
{
}
bool ServerTurnToMove::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerTurnToMove::execute(ReferenceCountPtr<State>& state){
	
	state->turnToMove(*this);
	
}

