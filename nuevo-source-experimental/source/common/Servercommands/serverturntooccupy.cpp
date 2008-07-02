#include "serverturntooccupy.h"

ServerTurnToOccupy::ServerTurnToOccupy(): ServerCommand(),TurnToOccupy()
{
}

ServerTurnToOccupy::ServerTurnToOccupy(const std::string & xml): ServerCommand(),TurnToOccupy(xml)
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

