#include "waitingplayer.h"
#include "stateobserver.h"
#include "../commands/youare.h"
#include "../commands/map.h"
#include "../commands/turntooccupy.h"
#include "../model/gamemanager.h"
#include "../Servercommands/serverreadytoplay.h"
#include <vector>
#include <sstream>
#include <fstream>

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
	
			
		gameManager->setWaitingPlay(false);
		gameManager->setPlaying(true);
	
		ReadyToPlay* ready =new ReadyToPlay();
		
		//uso el campo TO para setear la cantidad de players que hicieron readyToPlay
		ready->setTo(listaPlayerProxy.size());
		
		//se envia por socket al cliente
		this->gameManager->notify(ready);
	
		delete(ready);	
		
		//mando mapa a todos los clientes
	
		std::ifstream fileMap;
	
		std::string linea;
		std::string strMapa;
		strMapa.clear();
		
		//pido nombre del mapa seleccionado x 1er jugador a game
		std::string pathNom = "./maps/"+this->gameManager->getGame()->getMapa()->getMapName();
		
		fileMap.open(pathNom.c_str());
		
		//recorro archivo xml del mapa y lo voy guardando en un string
		while ( ! fileMap.eof() ){
				
			getline(fileMap, linea);
			strMapa += linea;		
		
		}
		
		//creo comando para enviar mapa a los clientes
		Map *mapaSeleccionado = new Map(strMapa);
		
		this->gameManager->notify(mapaSeleccionado);
	
		delete mapaSeleccionado;
		
		
		//std::cerr<< "Se envio el siguiente mapa a todos los clientes:"<< std::endl << strMapa<<std::endl;		
		std::cerr<< "Se envio el  mapa a todos los clientes"<<std::endl;
		
		
		//cambio a proximo estado que es ocupar
		this->gameManager->getStateMachine()->setState("occupying");
	
		std::cerr << "Cambio el estado a 'Occupying'" << std::endl;
		//ver turn tu occuppy
		
		//sorteo a ver que jugador empieza la ronda
		int jugadorEmpieza = this->gameManager->getGame()->getDice().roll( this->gameManager->getTurnManager()->getActivePlayerCount() );
		
		this->gameManager->getTurnManager()->setTurnOrder(jugadorEmpieza );
		
		std::cerr<< " Por sorteo empezara a jugar el jugador N° " << jugadorEmpieza << std::endl;
		
				//creo comando para enviar turn to occupy a los clientes
		std::vector<std::string> param;
		std::ostringstream jugOcupa;
		jugOcupa << jugadorEmpieza;
		
		param.push_back( jugOcupa.str() );
		
		TurnToOccupy *turnToOc = new TurnToOccupy(param);
		sleep(5);
		this->gameManager->notify(turnToOc);
	
		delete turnToOc;
	}	
	
	return false;


/*
	
	// marcar como ready to play
	// si todos listos, 
	//     Map 
	//     pasar a simplePopulating
	//     seleccionar primer jugador y TurnToOccupy
	return false;*/
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

