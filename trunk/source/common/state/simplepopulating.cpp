#include "simplepopulating.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include "../model/armybonuscalculator.h"
#include <list>

SimplePopulating::SimplePopulating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

SimplePopulating::~SimplePopulating()
{
}


bool SimplePopulating::populate(Populate & command){

	
	//si la accion es valida
	if ( command.validate(this->gameManager) ){
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//calculo ejercitos restantes del jugador actual, restandole los que se ubucaron en esta ronda.
		int ejercitosRestantes = playerActual->getArmyCount() - command.getArmyCount();
		
		//seteo al jugador actual la cant de ejercitos que le quedan por ubicar
		playerActual->setArmyCount( ejercitosRestantes );
		
						
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

		}
		
	}	
		//notificacion
		
		return true;
}

