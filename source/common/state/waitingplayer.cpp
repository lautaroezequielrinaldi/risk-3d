#include "waitingplayer.h"

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingPlayer::~WaitingPlayer()
{
}

bool WaitingPlayer::readyToPlay(ReadyToPlay & command){
	std::cerr << "Evento WaitingPlayer::readyToPlay" << std::endl;
	// marcar como ready to play
	// si todos listos, 
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;
}

bool WaitingPlayer::joinGame(JoinGame & command){
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



