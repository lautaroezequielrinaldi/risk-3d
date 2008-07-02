#include "serverselectmap.h"

ServerSelectMap::ServerSelectMap(): ServerCommand(),SelectMap()
{
}


ServerSelectMap::ServerSelectMap(const std::string & xml): ServerCommand(),SelectMap(xml)
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


