
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

BattleResult Battle::start(ReferenceCountPtr<GameManager>& gameManager){
	
	std::list<int> dadosAtacante;
	std::list<int> dadosDefensor;

	// att que necesito para luego de ejecutar la batalla, se actualice el modelo con el resultado
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisAtacante = map->obtenerPais( this->ataque->getAttackerLand() );
	ReferenceCountPtr<Pais> paisDefensor = map->obtenerPais( this->ataque->getAttackedLand() );	

	ReferenceCountPtr<Player> playerAtacante = game->getPlayer( gameManager->getTurnManager()->getCurrentPlayer() );
	ReferenceCountPtr<Player> playerDefensor = game->getPlayer( gameManager->getTurnManager()->getDefenderPlayer() );


	// tiro los dados para el atacante
	for(int i=0;i<this->ataque->getArmyCount();i++)
		dadosAtacante.push_back(this->dice->roll() );
	
	// tiro los dados para defensor
	for(int j=0;j<this->defensa->getArmyCount();j++)
		dadosDefensor.push_back(this->dice->roll() );
		
	// compara dados de atacante y defensor y obtiene el resultado de la batalla
	BattleResult resultadoBatalla = compareDice(dadosAtacante, dadosDefensor);	
	
	// actualizacion del modelo con respecto al resultado de la batalla

	// elimina del pais atacante, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisAtacante->removeArmies(resultadoBatalla.getAttackerResult());

	// elimina del pais defensor, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	//paisDefensor->removeArmies(resultadoBatalla.getDefenderResult());


	// verifico si hubo conquista

	// si pais defensor tenia la misma cantidad de ejercitos que los que perdio en la batalla
	if ( paisDefensor->getArmyCount() == abs(resultadoBatalla.getDefenderResult() ) ){
		
		// elimino al pais defensor de la lista de paises del player defensor
		playerDefensor->removeConqueredLand(this->defensa->getDefenderdLand());
		
		// agrego pais conquistado a la lista de paises del jugador atacante
		playerAtacante->addConqueredLand( this->ataque->getAttackerLand() );
		
		// elimino del paisAtacante los ejercitos que se mueven al pais conquistado.
		// el movimiento no se hace explicitamente ya que quedan los ejercitos en el pais conquistado y 
		// solo se agrega el pais conquistado a la lista de paises del atacante.
		paisAtacante->removeArmies( abs(resultadoBatalla.getDefenderResult() ) );

	}


	
	
	return resultadoBatalla;
	

}

