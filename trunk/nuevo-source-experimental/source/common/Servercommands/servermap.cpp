#include "servermap.h"

ServerMap::ServerMap()
{
}

ServerMap::~ServerMap()
{
}
bool ServerMap::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerMap::execute(ReferenceCountPtr<State>& state){
	
	state->map(*this);
	
}


