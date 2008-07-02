#include "serveryouare.h"

ServerYouAre::ServerYouAre(): ServerCommand(), YouAre()
{
}

ServerYouAre::ServerYouAre(const std::string & xml ): ServerCommand(), YouAre(xml)
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

