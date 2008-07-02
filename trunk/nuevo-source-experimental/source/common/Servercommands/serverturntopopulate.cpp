#include "serverturntopopulate.h"

ServerTurnToPopulate::ServerTurnToPopulate()
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


