#include "occupying.h"
#include "../commands/populate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include <list>

Occupying::Occupying(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Occupying::~Occupying()
{
}

bool Occupying::populate(Populate & command){

	bool accionValida = command.validateOccupy(this->gameManager);
	
	if ( accionValida ){

		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//agrego a la lista de paises del jugador, el pais ocupado.
		playerActual->addConqueredLand(command.getCountryDestination());

		//si quien esta jugando es el ultimo de la ronda
		if ( this->gameManager->getTurnManager()->getLastPlayer() == this->gameManager->getTurnManager()->getCurrentPlayer() ){
			
			//obtengo lista de jugadores
			std::list< ReferenceCountPtr<Player> > listaJug = game->getPlayerList();
			std::list<ReferenceCountPtr<Player> >::iterator it;	
			
			//disminuyo 1 ejercito a todos los jugadores de la cant de ejercitos a ubicar.
			for (it = listaJug.begin(); it != listaJug.end() ; ++it ){
				
				ReferenceCountPtr<Player> playerActual = *it;
				//seteo al jugador, un ejercito menos a ubicar.
				playerActual->setArmyCount( playerActual->getArmyCount() - 1 );	

			}
			
			// si ya se habitaron todos los paises del mapa
			if ( !map->areUninhabitedCountries() )
				// cambio alproximo estado: simplePopulating
				this->gameManager->setCurrentState("simplePopulating");
		}
		
		//cambio de turno
		this->gameManager->getTurnManager()->changeTurn();


		//notificacion		
		
	}
	else
		//notificacion de error
		
		
	return accionValida;        
        
}

