#include "waitingfirstplayer.h"
#include "../commands/joingame.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager> & gameManager)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(JoinGame & command){
	// stateMachine->setState("waitingMapSelection");
	return false;
}



