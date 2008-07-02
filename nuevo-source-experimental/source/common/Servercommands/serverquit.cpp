#include "serverquit.h"

ServerQuit::ServerQuit()
{
}

ServerQuit::~ServerQuit()
{
}
bool ServerQuit::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void ServerQuit::execute(ReferenceCountPtr<State>& state){
	
	state->quit(*this);
	
}

