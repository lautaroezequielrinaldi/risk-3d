#include "waitingplayer.h"

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
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



