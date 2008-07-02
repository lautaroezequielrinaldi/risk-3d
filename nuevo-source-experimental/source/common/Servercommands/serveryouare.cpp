#include "serveryouare.h"

ServerYouAre::ServerYouAre()
{
}

ServerYouAre::~ServerYouAre()
{
}

bool ServerYouAre::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void ServerYouAre::execute(ReferenceCountPtr<State>& state){
	
	state->youAre(*this);
	
}

