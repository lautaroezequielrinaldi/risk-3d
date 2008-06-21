#include "gamemanager.h"

GameManager::GameManager(): game (), turnManager ()
{
}

GameManager::GameManager( ReferenceCountPtr<Game> & game, ReferenceCountPtr<TurnManager> & turnManager):
game (game),
turnManager (turnManager){
	ReferenceCountPtr<GameManager> & gameManager = this;
	stateMachine = new StateMachine(gameManager);
	stateMachine->setState("waitingFirstPlayer");

	open = true;
	playing = false;
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
	/* codigo comentado para que compile EDITOR_TARGET, no falla en SERVER_TARGET
	playerProxy->setPlayer(game->addPlayer());


	*/
	// incrementar jugadores
	// si alcanzado max, open -> false;


}


bool GameManager::isPlaying() {
	return playing;

}

bool GameManager::isOpen() {
	return open;

}

std::list< ReferenceCountPtr<Player> >& GameManager::getPlayerList(){
	return game->getPlayerList();

}
