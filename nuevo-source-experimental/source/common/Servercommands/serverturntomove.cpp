#include "serverturntomove.h"

ServerTurnToMove::ServerTurnToMove()
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

