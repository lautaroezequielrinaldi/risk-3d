#include "waitingmapselection.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../model/gamemanager.h"
#include <vector>
#include <sstream>

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingMapSelection::~WaitingMapSelection()
{
}

bool WaitingMapSelection::joinGame(ServerJoinGame & command) {
	
	std::cerr << "Evento WaitingMapSelection::joinGame" << std::endl;

	//paso de "turno" para saber quien es el proximo jugador que se conecto.
	this->gameManager->getTurnManager()->changeTurn();

	std::vector<std::string> v;

	std::ostringstream jugActivos;
	jugActivos << this->gameManager->getGame()->getPlayerCount();

	v.push_back(jugActivos.str());

	YouAre * youare = new YouAre(v);
	
	youare->setTo(this->gameManager->getTurnManager()->getCurrentPlayer());
	//obtengo cant de jugadores q hay conectados.
	//youare->numeroJugador = this->gameManager->getGame()->getPlayerList().size();
	
	std::ostringstream strNumeroJugador;
	strNumeroJugador << this->gameManager->getTurnManager()->getCurrentPlayer();
	
	std::string saludoPrncipal = "Sos el jugador numero " + strNumeroJugador.str();
	youare->setMainMsg(saludoPrncipal);
	
	std::string saludoSecu = "Se ha conectado el jugador numero "+ strNumeroJugador.str();
	youare->setSecMsg(saludoSecu);
	
		
	//se envia por socket al cliente
	this->gameManager->notify(youare);
	
	delete(youare);


	return false;
}


bool WaitingMapSelection::readyToPlay(ServerReadyToPlay & command) {
	std::cerr << "Evento WaitingMapSelection::readyToPlay" << std::endl;
	// marcar como ready to play
	return false;
}


bool WaitingMapSelection::selectMap(ServerSelectMap & command){
	
	std::cerr << "Evento WaitingMapSelection::SelectMap" << std::endl;
	// ver si es el jugador actual
	// si ahora no hay lugar o todos estan ready to play
	//    Map
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy	
	return false;
}

void WaitingMapSelection::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

