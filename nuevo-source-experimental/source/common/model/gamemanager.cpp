#include "gamemanager.h"
#include <iostream>
#include <sstream>
#include "../commands/commandhydrator.h"
#include "../commands/uicommand.h"
#include "../Servercommands/serverattack.h"
#include "../commands/youare.h"

GameManager::GameManager(): StateObservable(), game (), turnManager ()
{
}

GameManager::GameManager( ReferenceCountPtr<Game> & game, ReferenceCountPtr<TurnManager> & turnManager):
game (game),
turnManager (turnManager){
	commandHydrator = new CommandHydrator();
	open = true;
	waitingPlay=false;
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

ServerAttack& GameManager::getAttack(){
	return *attack;
}
		 
void GameManager::setAttack(ServerAttack& attack){
	this->attack = &attack;
}

const unsigned int GameManager::getGameCapacity(){
	return CAPACIDAD_MAXIMA;
}

void GameManager::setWaitingPlay(bool state){
	this->waitingPlay = state;	
}
		
void GameManager::setPlaying(bool state){
	this->playing = state;
}

/**
 * @todo evaluar impacto contra reutilizacion en cliente
 */
void GameManager::add(ReferenceCountPtr<PlayerProxy> & playerProxy) {
	
	std::cerr<< "Cantidad de proxy playares en lista del GM: "<< proxyList.size()<<std::endl;
	
	//se crea un player dentro de Game y el mismo se pasa a setPlayer del playerProxy
	playerProxy->setPlayer(game->addPlayer());
	
	//se agrega el playerProxy a la lista que tiene el gameManager
	proxyList.push_back(playerProxy);
	
	//agrega el player a la lista del turnmanager
	this->turnManager->addPlayer(playerProxy->getPlayer()->getColor());
	/*
	std::vector<std::string> v;

	std::ostringstream numeroJugador;
	numeroJugador << playerProxy->getPlayer()->getColor();

	v.push_back(numeroJugador.str());

	YouAre * youare = new YouAre(v);
	playerProxy->notify(*youare);
	delete(youare);
*/
	// si alcanzado max, open -> false;
	if ( proxyList.size() == CAPACIDAD_MAXIMA ){
		this->open = false;
		this->waitingPlay = true;
	}

}

bool GameManager::isPlaying() {
	return playing;
}

bool GameManager::isOpen() {
	return open;
}

bool GameManager::isWaitingPlay(){
	return this->waitingPlay;
}

void GameManager::setMe(int me) {
	this->me = me;
}

int GameManager::getMe() {
	return me;
}

void notify(std::string msg){
	// para cada xProxy, pedir notify(msg);
}

std::list< ReferenceCountPtr<Player> >& GameManager::getPlayerList(){
	return game->getPlayerList();

}

std::list< ReferenceCountPtr<Proxy> >& GameManager::getPlayerProxyList(){
	return this->proxyList;
}	

void GameManager::execute(const std::string & commandName,const std::string &commandXml){

	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	
	std::cerr << "GameManager::execute( " << commandName << ")"<< std::endl;

	std::cerr << commandName << " -> execute("<< currentState->getName()<<")" <<std::endl << std::endl;
	
	ServerCommand* command = commandHydrator->getCommand(commandName,commandXml);
	
	if (command != NULL) 
		// Notifica a los listeners del comando.
		CommandObservable::notifyCommandExecuted(*command);

	
	
	// se hace un lock para que se ejecute un comando por vez nada mas.
	this->mutex.lock();
	
	// aca le estamos pidiendo al command que llame al metodo correspondiente
	// a si mismo del estado actual.
	command->execute(currentState);
	
	// deslockeo mutex
	this->mutex.unlock();
}

/**
 *
 * ojo, esto solo anda en el cliente, en el server hay que hacer el iterador....
 */
void GameManager::notify(Command * command) {
	
	std::cerr << "GameManager::notify(" << command->getName() << ")" << std::endl;
	std::cerr << "GameManager::notify from: " << command->getFrom() << " to: " << command->getTo() << std::endl;
		
	// se hace un lock para que se ejecute un comando por vez nada mas.
	//this->mutex.lock();
	
	ReferenceCountPtr<Proxy> actualProxy;
	
	std::list<ReferenceCountPtr<Proxy> >::iterator it;
	
	it =this->proxyList.begin();

	//se notifica a todos los proxyPlayers
	while ( it != this->proxyList.end()) {
		
		actualProxy = *it;
		
		//this->mutex.lock();
		    	
        actualProxy->notify(*command);
        
        //->mutex.unlock();
        
		++it;
	}

	// deslockeo mutex
	//this->mutex.unlock();
}


ReferenceCountPtr<State> GameManager::getCurrentState(){
	
	return this->stateMachine->getCurrentState();	
}
		 

void GameManager::setCurrentState( std::string stateName  ){
	
	this->stateMachine->setState(stateName);
	this->notifyStateChanged(*(this->stateMachine->getCurrentState()));
} 

ReferenceCountPtr<PlayerProxy> GameManager::getPlayerProxy(int color) {
	bool encontrado = false;
	ReferenceCountPtr<Proxy> actual;
	std::list<ReferenceCountPtr<Proxy> >::iterator it;

	it =this->proxyList.begin();
	/*busco en la lista de jugadores, al actual, usando el color del jugador q tiene el turno*/
	while ( it != this->proxyList.end() && !encontrado) {
	
		actual = *it;
		
		/*comparo color del jugador especificado con color del jugador de la iteracion*/
		if ( color == ((ReferenceCountPtr<PlayerProxy> )actual)->getPlayer()->getColor() )
			encontrado=true;
		else
			++it;
	}
	
	if( !encontrado )
		actual = NULL;
		
	return actual;


}


void GameManager::remove(int color) {
	proxyList.remove(getPlayerProxy(color));
	game->remove(color);
	

}

