#include "waitingfirstplayer.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(JoinGame & command){
	// aceptarlo
	// YouAre(n) 
	// marcar jugador como actual
	// enviar un comando SelectMap con los mapas hallados en la carpeta apropiada
	// stateMachine->setState("waitingMapSelection");
	return false;
}



