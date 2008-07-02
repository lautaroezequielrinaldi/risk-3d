#include "serverselectmap.h"

ServerSelectMap::ServerSelectMap()
{
}

ServerSelectMap::~ServerSelectMap()
{
}
bool ServerSelectMap::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar que el mapa exista	
		return false;
	
}

void ServerSelectMap::execute(ReferenceCountPtr<State>& state){
    state->selectMap(*this);

	
}


