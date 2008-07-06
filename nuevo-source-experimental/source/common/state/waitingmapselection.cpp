#include "waitingmapselection.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../Servercommands/serverselectmap.h"
#include "../Servercommands/serverreadytoplay.h"
#include "../model/gamemanager.h"

#include "../parser/mapaparser.h"

#include <vector>
#include <sstream>

WaitingMapSelection::WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingMapSelection::~WaitingMapSelection()
{
}

bool WaitingMapSelection::joinGame(ServerJoinGame & command) {
	
	std::cerr << "Evento WaitingMapSelection::joinGame" << std::endl;

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


	return false;
}


bool WaitingMapSelection::readyToPlay(ServerReadyToPlay & command) {

	std::cerr << "Evento WaitingMapSelection::readyToPlay" << std::endl;

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
		
		//uso el campo TO para setear la cantidad de players que hicieron readyToPlay
		ready->setTo(listaPlayerProxy.size());
		
		//se envia por socket al cliente
		this->gameManager->notify(ready);
	
		delete(ready);	
		
		//cambio a proximo estado que es ocupar
		this->gameManager->getStateMachine()->setState("Occupying");
	
		std::cerr << "Cambio el estado a 'Occupying'" << std::endl;
		//ver turn tu occuppy
		
	}	
	
	return false;
}


bool WaitingMapSelection::selectMap(ServerSelectMap & command){
	
	std::cerr << "En estado-evento WaitingMapSelection::SelectMap" << std::endl;
	
	MapaParser mapaParser;
	
	std::cerr << "Bajando xml mapa a memoria......." << std::endl;
	
	//levanto el mapa desde archivo xml a memoria
	ReferenceCountPtr<Mapa> mapa = mapaParser.loadMap(command.getMapName());

	std::cerr << "Guardando mapa bajado en Game.........." << std::endl;
	
	//seteo el mapa que se usara en el modelo del juego
	this->gameManager->getGame()->setMapa(mapa);
		
	//cambio a proximo estado
	this->gameManager->getStateMachine()->setState("waitingPlayer");
	
	std::cerr << "Hecho. Cambio el estado a 'WaitingPlayer'" << std::endl;

	// si ahora no hay lugar o todos estan ready to play

	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy	
	return false;
}

void WaitingMapSelection::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

