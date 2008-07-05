#include "waitingfirstplayer.h"
#include "stateobserver.h"
#include <iostream>
#include <fstream>
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

	std::ostringstream numeroJugador;
	numeroJugador << "1";

	v.push_back(numeroJugador.str());

	YouAre * youare = new YouAre(v);
	youare->setTo(1);
	//se envia por socket al cliente
	this->gameManager->notify(youare);
	
	delete(youare);
		
	//creo objeto para manejar archivo que contiene lista de nombres de mapas
	std::ifstream archivoMapas;
	
	std::string pathNom = "./configuration/mapList";
	
	archivoMapas.open(pathNom.c_str());
	v.clear();
	std::string linea;
	
	//recorro archivo 
	while ( ! archivoMapas.eof() ){
			
		getline(archivoMapas, linea);
		v.push_back(linea);
		std::cerr<< "linea del archivo de mapas: "<<linea<<std::endl;
		
	}

	archivoMapas.close();
	
	//se crea comando mapList para enviarlo al cliente
	MapList * mapList = new MapList(v);
	
	// se le envia al jugador de id 1 que es el que selecciona la lista de mapas.
	mapList->setTo(1);
	
	this->gameManager->notify(mapList);
	
	delete(mapList);

	this->gameManager->getStateMachine()->setState("waitingMapSelection");
	
	return false;
}

void WaitingFirstPlayer::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

