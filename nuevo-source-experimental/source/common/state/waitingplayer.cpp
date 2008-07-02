#include "waitingplayer.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../model/gamemanager.h"
#include <vector>

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

