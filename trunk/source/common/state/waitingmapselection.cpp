#include "waitingmapselection.h"

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
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



