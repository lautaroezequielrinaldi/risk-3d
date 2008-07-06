#include "waitingplayer.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../model/gamemanager.h"
#include "../Servercommands/serverreadytoplay.h"
#include <vector>
#include <sstream>

WaitingPlayer::WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingPlayer::~WaitingPlayer()
{
}

bool WaitingPlayer::readyToPlay(ServerReadyToPlay & command){

	std::cerr << "Evento WaitingPlayer::readyToPlay" << std::endl;


	//obtengo playerProxy que envio el readyToPlay
	ReferenceCountPtr<PlayerProxy> playerProxyFrom = this->gameManager->getPlayerProxy(command.getFrom());
	//lo seteo en ready to play
	playerProxyFrom->setReadyToPlay(true);
	
	//verifico si todos esta ready to play para pasar a modo juego
	std::list<ReferenceCountPtr<Proxy> > listaPlayerProxy = this->gameManager->getPlayerProxyList();
	std::list<ReferenceCountPtr<Proxy> >::iterator it;
	it = listaPlayerProxy.begin();
	bool todosListos = true;
	
	while ( it != listaPlayerProxy.end() && todosListos ){
		
		ReferenceCountPtr<Proxy> actual = *it;
		if ( ! ((ReferenceCountPtr<PlayerProxy> )actual)->isReadyToPlay() )
			todosListos = false;
		else
			++it;
	}
	
	//si todos los clientes ya esta listos para jugar y hay mas de 1
	if ( todosListos &&  listaPlayerProxy.size() > 1){
	
		ReadyToPlay* ready =new ReadyToPlay();
		
		//se envia por socket al cliente
		this->gameManager->notify(ready);
	
		delete(ready);	
		
		//cambio a proximo estado que es ocupar
		this->gameManager->getStateMachine()->setState("Occupying");
	
		std::cerr << "Cambio el estado a 'Occupying'" << std::endl;
		//ver turn tu occuppy
		
	}	
	
	return false;


/*
	std::vector<std::string> v;
	v.push_back("3");


	YouAre * youare = new YouAre(v);
	this->gameManager->notify(youare);
	delete(youare);
	return false;*/
	// marcar como ready to play
	// si todos listos, 
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;
}

bool WaitingPlayer::joinGame(ServerJoinGame & command){

	std::cerr << "Evento WaitingPlayer::joinGame" << std::endl;
	

	//paso de "turno" para saber quien es el proximo jugador que se conecto.
	this->gameManager->getTurnManager()->changeTurn();

	std::vector<std::string> v;

	std::ostringstream jugActivos;
	jugActivos << this->gameManager->getGame()->getPlayerCount();

	v.push_back(jugActivos.str());

	YouAre * youare = new YouAre(v);
	
	youare->setTo(this->gameManager->getTurnManager()->getCurrentPlayer());
	
	
	std::ostringstream strNumeroJugador;
	strNumeroJugador << this->gameManager->getTurnManager()->getCurrentPlayer();
	
	std::string saludoPrncipal = "Sos el jugador numero " + strNumeroJugador.str();
	youare->setMainMsg(saludoPrncipal);
	
	std::string saludoSecu = "Se ha conectado el jugador numero "+ strNumeroJugador.str();
	youare->setSecMsg(saludoSecu);
	
		
	//se envia por socket al cliente
	this->gameManager->notify(youare);
	
	delete(youare);


	
	
	// si hay lugar, 
	//	aceptarlo
	//      YouAre(n)
	// si ahora no hay lugar
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;
}

void WaitingPlayer::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

