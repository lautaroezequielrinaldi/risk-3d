#include "moving.h"
#include "../commands/move.h"
#include "../model/gamemanager.h"
#include "../model/armybonuscalculator.h"
#include "../model/player.h"

Moving::Moving(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Moving::~Moving()
{
}

bool Moving::move(Move & command){

	bool accionValida= command.validate ( this->gameManager);
	
	if( accionValida ){

		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		ReferenceCountPtr<Pais> paisO = map->obtenerPais(command.getCountryDestination());
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryOrigin());
		
		// elimina la cantidad de ejercitos que mueve del pais origen
		paisO->removeArmies(command.getArmyCount());
		
		// agrega la cantidad de ejercitos que se mueven, al pais destino
		paisD->addArmies(command.getArmyCount());
	
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
	
	
		//notifica el cambio
	}
	else
		//notificar error
	
	//a sacar
	return accionValida;
}


