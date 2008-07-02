#include "gamemanager.h"
#include <iostream>
#include <sstream>
#include "../commands/commandhydrator.h"
#include "../commands/uicommand.h"
#include "../Servercommands/serverattack.h"

GameManager::GameManager(): StateObservable(), game (), turnManager ()
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

ServerAttack& GameManager::getAttack(){
	return *attack;
}
		 
void GameManager::setAttack(ServerAttack& attack){
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
	//agrega el player a la lista del turnmanager
	this->turnManager->addPlayer(playerProxy->getPlayer()->getColor());
	
	std::vector<std::string> v;

	std::ostringstream numeroJugador;
	numeroJugador << playerProxy->getPlayer()->getColor();

	v.push_back(numeroJugador.str());

	YouAre * youare = new YouAre(v);
	playerProxy->notify(*youare);
	delete(youare);

	// si alcanzado max, open -> false;
	if ( proxyList.size() == CAPACIDAD_MAXIMA )
		this->open = false;

}

bool GameManager::isPlaying() {
	return playing;

}

bool GameManager::isOpen() {
	return open;

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
/**
 * @todo candidato a execute(UICommand
 *
 */
void GameManager::execute(UICommand * cmd){
	//std::cerr << "GameManager::execute("<< cmd->getName()<< ")"<< cmd->serialize() << std::endl;
	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	cmd->execute(currentState);
}

void GameManager::execute(const std::string & commandName,const std::string &commandXml){
	// obtener lock
	ReferenceCountPtr<State> currentState = stateMachine->getCurrentState();
	std::cerr << "GameManager::execute( " << commandName << ")"<< std::endl;
	std::cout << commandName << " -> execute("<< currentState->getName()<<")" <<std::endl << std::endl;
	ServerCommand* command = commandHydrator->getCommand(commandName,commandXml);
	if (command != NULL) {
        Command& cmd = reinterpret_cast<Command&>(*command);
		// Notifica a los listeners del comando.
		CommandObservable::notifyCommandExecuted(cmd);
	}	
	// aca le estamos pidiendo al command que llame al metodo correspondiente
	// a si mismo del estado actual.
	command->execute(currentState);
}

/**
 *
 * ojo, esto solo anda en el cliente, en el server hay que hacer el iterador....
 */
void GameManager::notify(Command * command) {
	std::cerr << "GameManager::notify(" << command->getName() << ")" << std::endl;
	std::cerr << "GameManager::notify from: " << command->getFrom() << " to: " << command->getTo() << std::endl;
	ReferenceCountPtr<Proxy> actualProxy;
	std::list<ReferenceCountPtr<Proxy> >::iterator it;
	it =this->proxyList.begin();

	while ( it != this->proxyList.end()) {
		actualProxy = *it;
		actualProxy->notify(*command);
		++it;
	}


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

