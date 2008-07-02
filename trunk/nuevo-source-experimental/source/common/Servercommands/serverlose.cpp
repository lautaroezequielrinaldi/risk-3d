#include "serverlose.h"

ServerLose::ServerLose(): Lose()
{
}

ServerLose::ServerLose(const std::string & xml) : Lose(xml)
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

