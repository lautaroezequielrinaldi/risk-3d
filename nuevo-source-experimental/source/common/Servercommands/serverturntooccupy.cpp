#include "serverturntooccupy.h"

ServerTurnToOccupy::ServerTurnToOccupy()
{
}

ServerTurnToOccupy::~ServerTurnToOccupy()
{
}

		
bool ServerTurnToOccupy::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerTurnToOccupy::execute(ReferenceCountPtr<State>& state){
	
	state->turnToOccupy(*this);
	
}

