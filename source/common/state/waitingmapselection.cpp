#include "waitingmapselection.h"
#include "../commands/joingame.h"
#include "../commands/selectmap.h"
#include "../commands/readytoplay.h"

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager> & gameManager)
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



