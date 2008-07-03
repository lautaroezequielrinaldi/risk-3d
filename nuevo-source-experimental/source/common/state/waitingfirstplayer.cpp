#include "waitingfirstplayer.h"
#include "stateobserver.h"
#include <iostream>
#include <sstream>

#include "../model/gamemanager.h"
#include "../commands/youare.h"
#include "../commands/maplist.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(ServerJoinGame & command){
	
	std::cerr << "Evento WaitingFirstPlayer::joinGame" << std::endl;

	this->gameManager->getTurnManager()->changeTurn(1);

	std::vector<std::string> v;

	// deberia levantar la lista de mapas existentes 
	v.push_back("mapa1");
	v.push_back("mapa2");
	v.push_back("mapa3");
	
	//se crea comando mapList para enviarlo al cliente
	MapList * mapList = new MapList(v);
	
	// se le envia al jugador de id 1 que es el que selecciona la lista de mapas.
	mapList->setTo(1);
	
	std::cerr << " SE VA A MANDAR EL MAPLIST COMMAND POR SOCKET"<< std::endl;
	this->gameManager->notify(mapList);
	
	delete(mapList);

	this->gameManager->getStateMachine()->setState("waitingMapSelection");
	
	return false;
}

void WaitingFirstPlayer::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

