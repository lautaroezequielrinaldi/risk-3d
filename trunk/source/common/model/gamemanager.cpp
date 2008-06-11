#include "gamemanager.h"

GameManager::GameManager():
game (),
turnManager ()
{
}

GameManager::GameManager( ReferenceCountPtr<Game> & game, ReferenceCountPtr<TurnManager> & turnManager):
game (game),
turnManager (turnManager)
{
	// no realiza ninguna accion
}

GameManager::~GameManager()
{
	// no realiza ninguna accion
}

ReferenceCountPtr<Game>& GameManager::getGame(){
	return this->game;	
}
		
ReferenceCountPtr<TurnManager>& GameManager::getTurnManager(){
	return this->turnManager;
}

