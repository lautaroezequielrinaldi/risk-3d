#include "waitingmapselection.h"
#include "../commands/youare.h"
#include "../model/gamemanager.h"
#include <vector>

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingMapSelection::~WaitingMapSelection()
{
}

bool WaitingMapSelection::joinGame(JoinGame & command) {
	std::cerr << "Evento WaitingMapSelection::joinGame" << std::endl;

/*	std::vector<std::string> v;
	v.push_back("2");


	YouAre * youare = new YouAre(v);
	this->gameManager->notify(youare,2);
	delete(youare);
*/
	return false;
}


bool WaitingMapSelection::readyToPlay(ReadyToPlay & command) {
	std::cerr << "Evento WaitingMapSelection::readyToPlay" << std::endl;
	// marcar como ready to play
	return false;
}


bool WaitingMapSelection::selectMap(SelectMap & command){
	std::cerr << "Evento WaitingMapSelection::SelectMap" << std::endl;
	// ver si es el jugador actual
	// si ahora no hay lugar o todos estan ready to play
	//    Map
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy	
	return false;
}



