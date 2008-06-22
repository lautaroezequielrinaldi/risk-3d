#include "gamemanager.h"
#include <iostream>
#include "../commands/commandhydrator.h"

GameManager::GameManager(): game (), turnManager ()
{
}

GameManager::GameManager( ReferenceCountPtr<Game> & game, ReferenceCountPtr<TurnManager> & turnManager):
game (game),
turnManager (turnManager){
	commandHydrator = new CommandHydrator();
	open = true;
	playing = false;
	attack = NULL;
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


Attack& GameManager::getAttack(){
	return *attack;
}
		 
void GameManager::setAttack(Attack& attack){
	this->attack = &attack;
}


/**
 * @todo evaluar impacto contra reutilizacion en cliente
 *
 *
 */
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
	// obtener lock
	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	std::cerr << "Estado actual: " << currentState->getName() << std::endl;
	
	ReferenceCountPtr<Command> command = commandHydrator->getCommand(commandName,commandXml);

	// aca le estamos pidiendo al command que llame al metodo correspondiente
	// a si mismo del estado actual.
	command->execute(currentState);
	

}

ReferenceCountPtr<State> GameManager::getCurrentState(){
	
	return this->stateMachine->getCurrentState();	
}
		 

void GameManager::setCurrentState( std::string stateName  ){
	
	this->stateMachine->setState(stateName);	
} 



