
#include "battle.h"
#include<stdlib.h>
#include<list>


Battle::Battle(ReferenceCountPtr<Attack>& ataque,ReferenceCountPtr<Defend>& defensa,ReferenceCountPtr<Dice>& dice):
ataque (ataque),
defensa(defensa),
dice (dice)
{
}

Battle::~Battle()
{
	// no realiza ninguna accion
}

BattleResult Battle::compareDice(std::list<int>attackerDice, std::list<int> defenderDice){
	
	//creo instancia de BattleResult para almacenar el resultado de la batalla.
	BattleResult resultadoBatalla(this->ataque->getAttackerLand(),this->defensa->getDefenderdLand() );
	
	// iteradores para recorrer lista de valores de dados
	std::list<int>::iterator itDef;
	std::list<int>::iterator itAt;
	
	//ordeno los vectores de valores de dados de menor a mayor
	attackerDice.sort();
	defenderDice.sort();
	
	// comparo los valores de los dados del atacante con los del defensor.
	//se compara hasta que terminan los del defensor ya que es quien tiene la posibilidad de elegir menos dados.
	itDef =defenderDice.end() ;
	itAt = attackerDice.end() ;
	
	while ( itDef != defenderDice.begin() ){
		//gano el atacante
		if ( *itAt > *itDef )
			//defensor pierde un ejercito
			resultadoBatalla.deletetDefenderArmy();
		// gana defensor
		else  
			resultadoBatalla.deletetAttackerArmy();
		
		--itDef;
		--itAt;
		
	}
	
	return resultadoBatalla;
}

BattleResult Battle::start(){
	
	std::list<int> dadosAtacante;
	std::list<int> dadosDefensor;
	
	// tiro los dados para el atacante
	for(int i=0;i<this->ataque->getArmyCount();i++)
		dadosAtacante.push_back(this->dice->roll() );
	
	// tiro los dados para defensor
	for(int j=0;j<this->defensa->getArmyCount();j++)
		dadosDefensor.push_back(this->dice->roll() );
		
	// compara dados de atacante y defensor y obtiene el resultado de la batalla
	BattleResult resultadoBatalla = compareDice(dadosAtacante, dadosDefensor);	
	
	return resultadoBatalla;
	

}

