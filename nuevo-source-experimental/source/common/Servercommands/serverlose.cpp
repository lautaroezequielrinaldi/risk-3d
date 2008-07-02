#include "serverlose.h"

ServerLose::ServerLose(): ServerCommand(),Lose()
{
}

ServerLose::ServerLose(const std::string & xml) :ServerCommand(), Lose(xml)
{
}

ServerLose::~ServerLose()
{
}

		
bool ServerLose::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerLose::execute(ReferenceCountPtr<State>& state){
	
	state->lose(*this);
	
}

