#include "serveryouare.h"

ServerYouAre::ServerYouAre(): ServerCommand(), YoAre()
{
}

ServerYouAre::ServerYouAre(const std::string & xml ): ServerCommand(), YoAre(xml)
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

