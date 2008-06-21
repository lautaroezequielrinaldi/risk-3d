#include "waitingfirstplayer.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(JoinGame & command){
	// stateMachine->setState("waitingMapSelection");
	return false;
}



