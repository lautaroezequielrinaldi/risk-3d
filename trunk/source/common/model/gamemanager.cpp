#include "gamemanager.h"
#include "../state/statemachine.h"

GameManager::GameManager(): game (), turnManager ()
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


ReferenceCountPtr<Attack>& GameManager::getAttack(){
	return this->attack;
}
		 
void GameManager::setAttack( ReferenceCountPtr<Attack>& attack){
	this->attack = attack;	
}

void GameManager::add(ReferenceCountPtr<PlayerProxy> & playerProxy) {

}


void GameManager::addFirst(ReferenceCountPtr<PlayerProxy> & playerProxy) {

	add(playerProxy);


}

bool GameManager::playing() {
	return false;

}

bool GameManager::open() {
	return false;

}

std::list< ReferenceCountPtr<Player> >& GameManager::getPlayerList(){
	return game->getPlayerList();

}
