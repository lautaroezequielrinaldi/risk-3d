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

void GameManager::setStateMachine(ReferenceCountPtr<StateMachine>& stateMachine) {
	this->stateMachine = stateMachine;
	
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


ReferenceCountPtr<StateMachine>& GameManager::getStateMachine(){
	return this->stateMachine;
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
	proxyList.push_back(playerProxy);
	// incorporar a contenedor
	// incrementar jugadores
	// si alcanzado max, open -> false;

}

void GameManager::add(ReferenceCountPtr<ServerProxy> & serverProxy) {
	proxyList.push_back(serverProxy);
}

bool GameManager::isPlaying() {
	return playing;

}

bool GameManager::isOpen() {
	return open;

}

void notify(std::string msg){
	// para cada xProxy, pedir notify(msg);
}

std::list< ReferenceCountPtr<Player> >& GameManager::getPlayerList(){
	return game->getPlayerList();

}

void GameManager::execute(std::string commandName, std::string commandXml){
	// obtener lock
	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	std::cerr << "Estado actual: " << currentState->getName() << std::endl;
	std::cout << "a punto de hidratar comando" << std::endl;	
	Command* command = commandHydrator->getCommand(commandName,commandXml);
	std::cout << "Hidrato comando" << std::endl;
	// aca le estamos pidiendo al command que llame al metodo correspondiente
	// a si mismo del estado actual.
	command->execute(currentState);
	

}

/**
 *
 * ojo, esto solo anda en el cliente, en el server hay que hacer el iterador....
 */
void GameManager::notify(Command * command) {
	std::cerr << "Se ha pedido notificacion de " << command->getName() << std::endl;
	// pedirle a cada elemento del contenedor full_write(msg)

	ReferenceCountPtr<Proxy> actualProxy;
	std::list<ReferenceCountPtr<Proxy> >::iterator it;
	it =this->proxyList.begin();

	while ( it != this->proxyList.end()) {
		actualProxy = *it;
		actualProxy->notify(command);
		++it;
	}


}


ReferenceCountPtr<State> GameManager::getCurrentState(){
	
	return this->stateMachine->getCurrentState();	
}
		 

void GameManager::setCurrentState( std::string stateName  ){
	
	this->stateMachine->setState(stateName);	
} 



