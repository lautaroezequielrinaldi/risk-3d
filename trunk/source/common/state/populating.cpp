#include "populating.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"

Populating::Populating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Populating::~Populating()
{
}
bool Populating::populate(Populate & command){

	bool accoinValida =false;
	
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
		
		// si luego de actualizar cant de ejercitos restantes del jugador, se quedo en cero.
		if ( playerActual->getArmyCount() == 0 )
			//cambio al proximo estado: attacking
			gameManager->setCurrentState("attacking");		
		
		//notificar cambios
	}
	else
		//notificar error
	
	
	//a sacar
	return accoinValida;	
}


