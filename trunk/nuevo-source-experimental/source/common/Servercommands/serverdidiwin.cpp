#include "serverdidiwin.h"

ServerDidIWin::ServerDidIWin()
{
}

ServerDidIWin::~ServerDidIWin()
{
}
bool ServerDidIWin::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}

void ServerDidIWin::execute(ReferenceCountPtr<State>& state){
	
	state->didIWin(*this);
	
}

