#include "simplepopulating.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include "../model/armybonuscalculator.h"
#include <list>


#include<iostream>

using namespace std;

SimplePopulating::SimplePopulating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

SimplePopulating::~SimplePopulating()
{
}


bool SimplePopulating::populate(Populate & command){

	bool accionValida =  command.validate(this->gameManager);
	
	//si la accion es valida
	if ( accionValida){
		
		cout<<"Estado: simple populating"<<endl;
		cout<<"Jugador: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cout<<"pais destino: "<<paisD->getNombre()<<endl;
		cout<<"ejercitos antes de poblar: "<<paisD->getArmyCount();
		cout<<"Cantidad de ejercitos a ubicar: "<<command.getArmyCount() <<endl;
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//calculo ejercitos restantes del jugador actual, restandole los que se ubucaron en esta ronda.
		int ejercitosRestantes = playerActual->getArmyCount() - command.getArmyCount();
		
		//seteo al jugador actual la cant de ejercitos que le quedan por ubicar
		playerActual->setArmyCount( ejercitosRestantes );
		
		cout<<"ejercitos despues de poblar: "<<paisD->getArmyCount();
		cout<<"Al jugador "<<playerActual->getColor()<<" le quedan: "<<playerActual->getArmyCount()<<" ejerctos para ubicar"<<endl;
		
	
	
		//obtengo lista de jugadores
		std::list< ReferenceCountPtr<Player> > listaJug = game->getPlayerList();
		std::list<ReferenceCountPtr<Player> >::iterator it;	
		bool noMasEjercitos= true;
		it = listaJug.begin();
			
		//verifico si todos los jugadores estan con cero ejercitos para ubicar
		while ( it != listaJug.end() && noMasEjercitos ){
				
			ReferenceCountPtr<Player> playerActual = *it;
				//si al jugador actual de la lista le quedan ejercitos por ubicar
				if ( playerActual->getArmyCount() != 0 )
					noMasEjercitos = false;
		}
			
		// sino hay mas ejercitos en ningun jugador para ubicar
		if ( noMasEjercitos ){
				
			cout<<"ningun jugador tiene mas ejercitos por ubicar en la etapa inicial"<<endl;
						
			//cambio de turno
			this->gameManager->getTurnManager()->changeTurn();
				
			//creo un calculador de bonus 
			ArmyBonusCalculator calculadorBonus;
				
			//obtengo jugador actual ( el que jugara )
			ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
				
			//le asigno al jugador que ahora tiene el turno, el bonus de ejercitos que usara para poblar.
			playerActual->setArmyCount(calculadorBonus.getArmyBonus(this->gameManager));
				
			//cambio a proximo estado
			this->gameManager->setCurrentState("populating");
		
			cout<<"Turno de poblar juego para el jugador: "<<playerActual->getColor()<<endl;
			cout<<"El bonus de ejercitos es: "<<playerActual->getArmyCount()<<endl;
		}
		//si todavia quedan jugadores con ejercitos a ubucar
		else
			//cambio de turno
			this->gameManager->getTurnManager()->changeTurn();
	

	}
	
	return accionValida;
}

