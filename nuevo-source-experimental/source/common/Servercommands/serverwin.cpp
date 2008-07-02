#include "serverwin.h"

ServerWin::ServerWin(): ServerCommand(), Win()
{
}


ServerWin::ServerWin(const std::string & xml): ServerCommand(), Win(xml)
{
} 

ServerWin::~ServerWin()
{
}

bool ServerWin::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerWin::execute(ReferenceCountPtr<State>& state){
	
	state->win(*this);
	
}



