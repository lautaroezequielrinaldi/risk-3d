#include "waitingplayer.h"
#include "../commands/joingame.h"
#include "../commands/readytoplay.h"

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager> & gameManager)
{
}

WaitingPlayer::~WaitingPlayer()
{
}

bool WaitingPlayer::readyToPlay(ReadyToPlay & command){
	return false;
}

bool WaitingPlayer::joinGame(JoinGame & command){
	
	return false;
}



