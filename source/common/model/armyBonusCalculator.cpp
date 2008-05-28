#include "armyBonusCalculator.h"

ArmyBonusCalculator::ArmyBonusCalculator(Player& player, Mapa& map ) :jugador ( player ), mapa ( map)
{
}

ArmyBonusCalculator::~ArmyBonusCalculator()
{
}

int ArmyBonusCalculator::getArmyBonusPerCountry(){
	
	int cantEjercitos=0;
	
	/*si el jugador tiene menos de 9 paises conquistados*/
	if ( this->jugador.getConqueredLands() <= 9 )
		cantEjercitos = 3;
	/*si el resto de dividir la cant de ejercitos del jugador por 3, es cero*/
	else{
		if ( this->jugador.getConqueredLands() % 3  == 0 )
			/*se le da como bonus de ejercitos la cantidad que tiene / 3*/
			cantEjercitos = this->jugador.getConqueredLands()/3;
		else
			/*se le da como bonus de ejercitos la cantidad que tiene / 3  + 1 */
			cantEjercitos = this->jugador.getConqueredLands()/3 + 1;
	}
	
	return cantEjercitos;
	
	
}
		

int ArmyBonusCalculator::getArmyBonusPerContinent(){
	
	int bonus= 0;
	std::list< std::string>::iterator it;
	ReferenceCountPtr<Continente> continenteActual;
	

    /* Itero por cada continente del jugador*/
    for (it = this->jugador.getConqueredContinentList().begin(); it != this->jugador.getConqueredContinentList().end();++it) {
        /*obtengo nombre del continente actual*/
        std::string nombreContinente = *it;
        
        /*obtengo continente actual a partir del nombre*/
        continenteActual = this->mapa.obtenerContinente(nombreContinente);
        
        /*acumulo el bonus que proveen los continentes*/
        bonus += continenteActual->getArmyBonus();
    }
    
    return bonus;
	
}

int ArmyBonusCalculator::ArmyBonusCalculator::getArmyBonus(){
	
	return ( getArmyBonusPerCountry()+getArmyBonusPerContinent() );

}

