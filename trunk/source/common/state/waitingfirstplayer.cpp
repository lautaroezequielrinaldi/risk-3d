#include "waitingfirstplayer.h"
#include <iostream>
#include "../model/gamemanager.h"
#include "../commands/youare.h"

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
	// marcar jugador como actual
	// enviar un comando SelectMap con los mapas hallados en la carpeta apropiada
	// stateMachine->setState("waitingMapSelection");
	return false;
}



