#include "serverchat.h"

ServerChat::ServerChat()
{
}

ServerChat::~ServerChat()
{
}
bool ServerChat::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}

void ServerChat::execute(ReferenceCountPtr<State>& state){
	
	state->chat(*this);
	
}

