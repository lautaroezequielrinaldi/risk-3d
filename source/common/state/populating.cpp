#include "populating.h"
#include "stateobserver.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"

#include<iostream>

using namespace std;

Populating::Populating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Populating::~Populating()
{
}
bool Populating::populate(Populate & command){
	std::cerr << "Evento Populating::populate" << std::endl;
	bool accoinValida =false;
	
	//si la accion es valida
	if ( command.validate(this->gameManager) ){
		
		cout<<"Estado: populating"<<endl;
		cout<<"Jugador: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cout<<"pais destino: "<<paisD->getNombre()<<endl;
		cout<<"ejercitos antes de poblar: "<<paisD->getArmyCount()<<endl;
		cout<<"Cantidad de ejercitos a ubicar: "<<command.getArmyCount() <<endl;
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//calculo ejercitos restantes del jugador actual, restandole los que se ubucaron en esta ronda.
		int ejercitosRestantes = playerActual->getArmyCount() - command.getArmyCount();
		
		//seteo al jugador actual la cant de ejercitos que le quedan por ubicar
		playerActual->setArmyCount( ejercitosRestantes );
		
		cout<<"ejercitos despues de poblar: "<<paisD->getArmyCount()<<endl;
		cout<<"Al jugador "<<playerActual->getColor()<<" le quedan: "<<playerActual->getArmyCount()<<" ejerctos para ubicar"<<endl;
		
		
		// si luego de actualizar cant de ejercitos restantes del jugador, se quedo en cero.
		if ( playerActual->getArmyCount() == 0 ){

			//cambio al proximo estado: attacking
			gameManager->setCurrentState("attacking");		
			
			cout<<"HORA DE ATACAR"<<endl;
		}
		//notificar cambios
	}
	else
		//notificar error
		cout<<"poblamiento invalido"<<endl;
	
	return accoinValida;	
}

void Populating::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

