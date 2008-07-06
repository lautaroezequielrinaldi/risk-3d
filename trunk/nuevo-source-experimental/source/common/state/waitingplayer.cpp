#include "waitingplayer.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../model/gamemanager.h"
#include <vector>
#include <sstream>

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingPlayer::~WaitingPlayer()
{
}

bool WaitingPlayer::readyToPlay(ServerReadyToPlay & command){
	std::cerr << "Evento WaitingPlayer::readyToPlay" << std::endl;

/*
	std::vector<std::string> v;
	v.push_back("3");


	YouAre * youare = new YouAre(v);
	this->gameManager->notify(youare);
	delete(youare);
	return false;*/
	// marcar como ready to play
	// si todos listos, 
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;
}

bool WaitingPlayer::joinGame(ServerJoinGame & command){

	std::cerr << "Evento WaitingPlayer::joinGame" << std::endl;
	

	//paso de "turno" para saber quien es el proximo jugador que se conecto.
	this->gameManager->getTurnManager()->changeTurn();

	std::vector<std::string> v;

	std::ostringstream jugActivos;
	jugActivos << this->gameManager->getGame()->getPlayerCount();

	v.push_back(jugActivos.str());

	YouAre * youare = new YouAre(v);
	
	youare->setTo(this->gameManager->getTurnManager()->getCurrentPlayer());
	
	
	std::ostringstream strNumeroJugador;
	strNumeroJugador << this->gameManager->getTurnManager()->getCurrentPlayer();
	
	std::string saludoPrncipal = "Sos el jugador numero " + strNumeroJugador.str();
	youare->setMainMsg(saludoPrncipal);
	
	std::string saludoSecu = "Se ha conectado el jugador numero "+ strNumeroJugador.str();
	youare->setSecMsg(saludoSecu);
	
		
	//se envia por socket al cliente
	this->gameManager->notify(youare);
	
	delete(youare);


	
	
	// si hay lugar, 
	//	aceptarlo
	//      YouAre(n)
	// si ahora no hay lugar
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;
}

void WaitingPlayer::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

