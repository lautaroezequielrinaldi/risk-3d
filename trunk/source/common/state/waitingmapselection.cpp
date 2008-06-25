#include "waitingmapselection.h"

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingMapSelection::~WaitingMapSelection()
{
}

bool WaitingMapSelection::joinGame(JoinGame & command) {
	std::cerr << "Evento WaitingMapSelection::joinGame" << std::endl;
	// si hay lugar
	//    aceptarlo
	//    YouAre(n) 
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
	//     seleccionar primer jugador y TurnToOcuppy	
	return false;
}



