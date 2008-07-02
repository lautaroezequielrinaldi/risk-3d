#include "servernomore.h"

ServerNoMore::ServerNoMore(): ServerCommand(), NoMore()
{
}

ServerNoMore::ServerNoMore(const std::string & xml): ServerCommand(), NoMore(xml)
{
}

ServerNoMore::~ServerNoMore()
{
}
bool ServerNoMore::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}



void ServerNoMore::execute(ReferenceCountPtr<State>& state){
	
	state->noMore(*this);
	
}


