#include "servermap.h"

ServerMap::ServerMap(): Map()
{
}

ServerMap::ServerMap(const std::string & xml) : Map( xml )
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


