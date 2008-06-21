#include "gamemanager.h"

GameManager::GameManager(): game (), turnManager ()
{
}

GameManager::GameManager( ReferenceCountPtr<Game> & game, ReferenceCountPtr<TurnManager> & turnManager):
game (game),
turnManager (turnManager){
	open = true;
	playing = false;
}

void GameManager::prepare(ReferenceCountPtr<GameManager>& gameManager) {
	stateMachine = new StateMachine(gameManager);
	stateMachine->setState("waitingFirstPlayer");
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
	/* codigo comentado para que compile EDITOR_TARGET, no falla en SERVER_TARGET*/
	playerProxy->setPlayer(game->addPlayer());


	
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

void GameManager::execute(std::string commandName, std::string commandXml){
	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	// obtener CommandFactory a partir de commmandName
	// construir comando a partir de commandXml
	

	//stateMachine->getCurrentState

}
