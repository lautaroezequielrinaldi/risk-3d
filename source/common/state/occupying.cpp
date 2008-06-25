#include "occupying.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include <list>


#include<iostream>

using namespace std;

Occupying::Occupying(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Occupying::~Occupying()
{
}

bool Occupying::populate(Populate & command){
	std::cerr << "Evento Occupying::populate" << std::endl;
	bool accionValida = command.validateOccupy(this->gameManager);
	
	if ( accionValida ){

		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cout<<"Estado: OCUPANDO"<<endl;
		cout<<"pais destino: "<<paisD->getNombre()<<endl;
		cout<<"ejercitos antes de ocupar: "<<paisD->getArmyCount();
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		cout<<"ejercitos despues de ocupar: "<<paisD->getArmyCount()<<endl;
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//agrego a la lista de paises del jugador, el pais ocupado.
		playerActual->addConqueredLand(command.getCountryDestination());
		
		//disminuyo en 1 la cant de ejercitos a ubicar
		playerActual->setArmyCount( playerActual->getArmyCount() - 1 );
		
		cout<<"Cantidad de paises conquistados por el jugador "<<playerActual->getColor()<<" :"<<playerActual->getConqueredLands();
	
		// si ya se habitaron todos los paises del mapa
		if ( !map->areUninhabitedCountries() ){
			
			// cambio alproximo estado: simplePopulating
			this->gameManager->setCurrentState("simplePopulating");
			
			//cambio de turno al 1er jugador
			this->gameManager->getTurnManager()->changeTurn( this->gameManager->getTurnManager()->getFirstPlayer() );
			
			cout<<"HORA DE POBLAR INICIAL"<<endl;	
		}
		else
			//cambio de turno 
			this->gameManager->getTurnManager()->changeTurn();


		//notificacion
		cout<<"Le toca jugar al jugador: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;	
		
		
	}
	else
		//notificacion de error
		cout<<"Ocupamiento invalido"<<endl;
		
		
	return accionValida;        
        
}

