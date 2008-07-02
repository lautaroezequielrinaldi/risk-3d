#include "servernoroom.h"

ServerNoRoom::ServerNoRoom()
{
}

ServerNoRoom::~ServerNoRoom()
{
}
bool ServerNoRoom::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void ServerNoRoom::execute(ReferenceCountPtr<State>& state){
	
	state->noRoom(*this);
	
}

