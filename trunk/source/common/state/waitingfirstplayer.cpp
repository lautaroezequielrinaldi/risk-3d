#include "waitingfirstplayer.h"
#include <iostream>
#include "../model/gamemanager.h"
#include "../commands/youare.h"
#include "../commands/selectmap.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(JoinGame & command){
	std::cerr << "Evento WaitingFirstPlayer::joinGame" << std::endl;

	// aceptarlo

	gameManager->getTurnManager()->getCurrentPlayer();

	YouAre * youare = new YouAre();
	
	this->gameManager->notify(youare);

	this->gameManager->getTurnManager()->changeTurn(1);
	
	SelectMap * selectMap = new SelectMap();
	this->gameManager->notify(selectMap);

	gameManager->getStateMachine()->setState("waitingMapSelection");
	return false;
}



