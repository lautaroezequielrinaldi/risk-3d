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

	//creo objeto para manejar archivo que contiene lista de nombres de mapas
	std::ifstream archivoMapas;
	
	std::string pathNom = "./configuration/mapList";
	
	archivoMapas.open(pathNom.c_str());
	std::vector<std::string> v;
	std::string linea;
	
	//recorro archivo 
	//while ( ! archivoMapas.eof() ){
	for( int i=0; i< 6 ;i++){
		
		getline(archivoMapas, linea);
		v.push_back(linea);
		std::cerr<< "linea del archivo de mapas: "<<linea<<std::endl;
		
	}

	archivoMapas.close();
	
	//se crea comando mapList para enviarlo al cliente
	MapList * mapList = new MapList(v);
	
	// se le envia al jugador de id 1 que es el que selecciona la lista de mapas.
	mapList->setTo(1);
	
	std::cerr << " SE VA A MANDAR EL MAPLIST COMMAND"<< std::endl;
	this->gameManager->notify(mapList);
	
	delete(mapList);

	this->gameManager->getStateMachine()->setState("waitingMapSelection");
	
	return false;
}

void WaitingFirstPlayer::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

