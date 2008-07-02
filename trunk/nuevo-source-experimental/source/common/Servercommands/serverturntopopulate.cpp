#include "serverturntopopulate.h"

ServerTurnToPopulate::ServerTurnToPopulate(): ServerCommand(), TurnToPopulate()
{
}

ServerTurnToPopulate::ServerTurnToPopulate(const std::string & xml): ServerCommand(), TurnToPopulate(xml)
{
}

ServerTurnToPopulate::~ServerTurnToPopulate()
{
}
bool ServerTurnToPopulate::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerTurnToPopulate::execute(ReferenceCountPtr<State>& state){
	
	state->turnToPopulate(*this);
	
}


