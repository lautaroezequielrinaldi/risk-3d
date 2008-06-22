#include "waitingplayer.h"

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingPlayer::~WaitingPlayer()
{
}

bool WaitingPlayer::readyToPlay(ReadyToPlay & command){
	// marcar como ready to play
	// si todos listos, 
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOcuppy
	return false;
}

bool WaitingPlayer::joinGame(JoinGame & command){
	// si hay lugar, 
	//	aceptarlo
	//      YouAre(n)
	// si ahora no hay lugar
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOcuppy
	return false;
}



