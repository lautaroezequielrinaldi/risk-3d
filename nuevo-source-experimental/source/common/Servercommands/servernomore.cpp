#include "servernomore.h"

ServerNoMore::ServerNoMore()
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


