#include "serverpopulate.h"

#include <sstream>
#include "../model/armybonuscalculator.h"

#include<iostream>
using namespace std;

ServerPopulate::ServerPopulate(): ServerCommand(), Populate()
{
}

ServerPopulate::ServerPopulate(const std::string & xml): ServerCommand(), Populate(xml)
{
}


ServerPopulate::~ServerPopulate()
{
}


bool ServerPopulate::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool resul=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	std::string pDestino = this->getCountryDestination();
	//si el pais destino es del jugador actual
	if( jugadorActual->landOwner(pDestino) ){	
		//si la cant de ejercitos a usar es menor o igual que la cantidad disponible del jugador
		if (this->getArmyCount() <=  jugadorActual->getArmyCount() )
			resul= true;
		else
			cerr<<"no tenes esa cantidad de ejercitos disponibles!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	}
	else
		cerr<<"no es tu pais!!!!!!!!!!!!!!!!!"<<endl;
	
	return resul;
	
}

bool ServerPopulate::validateOccupy(ReferenceCountPtr<GameManager>& gameManager){

	bool res = false;

	ReferenceCountPtr<Game> game = gameManager->getGame();

	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisD = map->obtenerPais(this->getCountryDestination());


	// si pais destino esta vacio
	if ( paisD->getArmyCount() == 0 ){
		// si quiere ubicar solo 1 ejercito
		if ( this->getArmyCount() == 1 )
			res = true;
		else
			cerr<<"NO PUEDE UBICAR MAS DE UN EJERCITO"<<endl;
	}    
	else
		cerr<<"PAIS YA OCUPADO"<<endl;


	return res;
}


void ServerPopulate::execute(ReferenceCountPtr<State>& state){
	
	state->populate(*this);
	
}


