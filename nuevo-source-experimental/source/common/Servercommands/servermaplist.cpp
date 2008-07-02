#include "servermaplist.h"

ServerMapList::ServerMapList()
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

