#include "waitingmapselection.h"

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingMapSelection::~WaitingMapSelection()
{
}

bool WaitingMapSelection::joinGame(JoinGame & command) {
	return false;
}


bool WaitingMapSelection::readyToPlay(ReadyToPlay & command) {
	return false;
}


bool WaitingMapSelection::selectMap(SelectMap & command){
	
	return false;
}



