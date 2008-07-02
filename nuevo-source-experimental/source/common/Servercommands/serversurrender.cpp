#include "serversurrender.h"

ServerSurrender::ServerSurrender()
{
}

ServerSurrender::~ServerSurrender()
{
}

bool ServerSurrender::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void ServerSurrender::execute(ReferenceCountPtr<State>& state){
	
	state->surrender(*this);
	
}



