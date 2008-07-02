#include "servermove.h"

#include <sstream>
#include<iostream>
using namespace std;

ServerMove::ServerMove() : ServerCommand(), Move()
{
}

ServerMove::ServerMove(const std::string & xml) : ServerCommand(), Move(xml)
{
}


ServerMove::~ServerMove()
{
}


bool ServerMove::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool movimValido=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisO = map->obtenerPais(this->getCountryOrigin());
	
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	std::string pOr =this->getCountryOrigin();
	std::string pDe =this->getCountryDestination();
	
	//si el pais origen es del jugador actual
	if( jugadorActual->landOwner(pOr) ){
	//si el pais destino es del jugador actual
		if( jugadorActual->landOwner(pDe) ){	
			//si pais origen es adyacente al pais destino
			if( paisO->esAdyacente(this->getCountryDestination())){
				//si la cantidad de ejercitos a mover es menor a la cantidad de ejercitos que tiene el pais origen
				if ( this->getArmyCount() < paisO->getArmyCount() )
					movimValido = true;
				else
					cerr<<"error, solo se puede mover una cantidad de ejercitos MENOR al total que posee el pais"<<endl;
			}
			else
				cerr<<"solo se permiten movimientos entre paises adyacentes, error."<<endl;
		}
		else
			cerr<<"el pais destino al cual queres mover ejercitos......no es tuyo!!!"<<endl;
	}
	else
		cerr<<"el pais origen desde el cual queres mover ejercitos......no es tuyo!!!"<<endl;
		
	return movimValido;
	
}

void  ServerMove::execute(ReferenceCountPtr<State>& state){
	
	state->move(*this);
	
	
}

