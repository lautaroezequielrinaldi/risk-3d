#include "armybonuscalculator.h"



using namespace std;

ArmyBonusCalculator::ArmyBonusCalculator()
{
	//no realiza ninguna accion
}

ArmyBonusCalculator::~ArmyBonusCalculator()
{
	//no realiza ninguna accion
}

int ArmyBonusCalculator::getArmyBonusPerCountry(ReferenceCountPtr<GameManager>& gameManager){
	
	int cantEjercitos=0;
	
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	// obtengo id del jug actual
	int currentPlayer = turnManager->getCurrentPlayer();
	
	/*obtengo jugador actual*/
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Player> actualPlayer = game->getPlayer(currentPlayer);
	

	if ( actualPlayer!= NULL ){
		
		/*si el jugador tiene menos de 9 paises conquistados*/
		if ( actualPlayer->getConqueredLands() <= 9 )
			cantEjercitos = 3;
		/*si el resto de dividir la cant de ejercitos del jugador por 3, es cero*/
		else{
			if ( actualPlayer->getConqueredLands() % 3  == 0 )
				/*se le da como bonus de ejercitos la cantidad que tiene / 3*/
				cantEjercitos = actualPlayer->getConqueredLands()/3;
			else
				/*se le da como bonus de ejercitos la cantidad que tiene / 3  + 1 */
				cantEjercitos = actualPlayer->getConqueredLands()/3 + 1;
		}
	}
	
	return cantEjercitos;
	
}
		
int ArmyBonusCalculator::getArmyBonusPerContinent(ReferenceCountPtr<GameManager>& gameManager){
	
	int bonus= 0;
	ReferenceCountPtr<Continente> continenteActual;
	std::list<std::string>::iterator it;
	
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map =game->getMapa(); 
	
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	// obtengo id del jugador actual
	int currentPlayer = turnManager->getCurrentPlayer();
	
	/*obtengo jugador actual*/
	ReferenceCountPtr<Player> actualPlayer = game->getPlayer(currentPlayer);
	
	if ( actualPlayer!= NULL ){

	    /* Itero por cada continente del jugador*/
	    for (it = actualPlayer->getConqueredContinentList().begin(); it != actualPlayer->getConqueredContinentList().end();++it) {
	        /*obtengo nombre del continente actual*/
	        std::string nombreContinente = *it;
	        
	        /*obtengo continente actual a partir del nombre*/
	        continenteActual = map->obtenerContinente(nombreContinente);
	        
	        /*acumulo el bonus que proveen los continentes*/
	        bonus += continenteActual->getArmyBonus();
	    }
	}
    
    return bonus;
	
}

int ArmyBonusCalculator::ArmyBonusCalculator::getArmyBonus(ReferenceCountPtr<GameManager>& gameMAnager){
	
	return ( getArmyBonusPerCountry(gameMAnager)+getArmyBonusPerContinent(gameMAnager) );

}

