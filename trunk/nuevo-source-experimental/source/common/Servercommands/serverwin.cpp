#include "serverwin.h"

ServerWin::ServerWin()
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



