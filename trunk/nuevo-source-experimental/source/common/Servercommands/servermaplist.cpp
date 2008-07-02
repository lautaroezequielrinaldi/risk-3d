#include "servermaplist.h"

ServerMapList::ServerMapList(): ServerCommand(), MapList()
{
}

ServerMapList::ServerMapList(const std::string & xml): ServerCommand(), MapList(xml)
{
}


ServerMapList::~ServerMapList()
{
}
void ServerMapList::execute(ReferenceCountPtr<State>& state){
	
	state->mapList(*this);
	
}

bool ServerMapList::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}

