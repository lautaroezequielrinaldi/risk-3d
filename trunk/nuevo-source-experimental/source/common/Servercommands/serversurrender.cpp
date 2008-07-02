#include "serversurrender.h"

ServerSurrender::ServerSurrender(): ServerCommand(),, Surrender()
{
}
ServerSurrender::ServerSurrender(const std::string & xml): ServerCommand(), Surrender(xml)
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



