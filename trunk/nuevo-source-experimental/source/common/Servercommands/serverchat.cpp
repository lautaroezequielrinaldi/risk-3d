#include "serverchat.h"

ServerChat::ServerChat(const std::string & xml): ServerCommand(), Chat (xml )
{
}

ServerChat::ServerChat() : ServerCommand(), Chat()
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

