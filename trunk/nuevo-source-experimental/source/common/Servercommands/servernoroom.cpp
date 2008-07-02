#include "servernoroom.h"

ServerNoRoom::ServerNoRoom() : ServerCommand(), NoRoom()
{
}
ServerNoRoom::ServerNoRoom(const std::string & xml) : ServerCommand(), NoRoom(xml)
{
}

ServerNoRoom::~ServerNoRoom()
{
}
bool ServerNoRoom::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void ServerNoRoom::execute(ReferenceCountPtr<State>& state){
	
	state->noRoom(*this);
	
}

