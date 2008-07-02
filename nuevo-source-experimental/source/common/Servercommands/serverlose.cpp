#include "serverlose.h"

ServerLose::ServerLose()
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

