#include "serverquit.h"

ServerQuit::ServerQuit(): ServerCommand(), Quit()
{
}

ServerQuit::ServerQuit(const std::string & xml): ServerCommand(), Quit(xml)
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

