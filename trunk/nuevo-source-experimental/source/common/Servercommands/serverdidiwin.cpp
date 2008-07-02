#include "serverdidiwin.h"

ServerDidIWin::ServerDidIWin(): DidIWin()
{
}

ServerDidIWin::ServerDidIWin(const std::string & xml) : DidIWin(xml)
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

