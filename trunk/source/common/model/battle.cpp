/**
 *
 * Esta clase deberia crear y enviar los comandos Kill, SetOwner y Move apropiados
 *
 */

#include "battle.h"
#include<stdlib.h>
#include<list>

#include<iostream>

using namespace std;


Battle::Battle(Attack& ataque,Defend& defensa,Dice& dice):
ataque (ataque),
defensa(defensa),
dice (dice)
{
}

Battle::~Battle()
{
	// no realiza ninguna accion
}

BattleResult Battle::compareDice(std::list<int> attackerDice, std::list<int> defenderDice, int attackerPlayer, int defenderPlayer){
	
	//creo instancia de BattleResult para almacenar el resultado de la batalla.
	BattleResult resultadoBatalla(this->ataque.getAttackerLand(),this->defensa.getDefenderdLand(),attackerPlayer,defenderPlayer );
	
	// iteradores para recorrer lista de valores de dados
	std::list<int>::reverse_iterator itDef;
	std::list<int>::reverse_iterator itAt;
	
	//ordeno los vectores de valores de dados de  *_ menor a mayor _*
	attackerDice.sort();
	defenderDice.sort();
			
	// comparo los valores de los dados del atacante con los del defensor.
	//se compara hasta que terminan los del defensor ya que es quien tiene la posibilidad de elegir menos dados.
	// rbegin deja apuntando el iterador en el ultimo elem de la lista 
	itDef =defenderDice.rbegin() ;
	itAt = attackerDice.rbegin() ;

	while ( itDef != defenderDice.rend() ){

		//gano el atacante
		if ( *itAt > *itDef )
			//incremento la cant de ejercitos perdidos por el defensor
			resultadoBatalla.incrementDefenderLostArmy();
		// gana defensor
		else  
			//incremento la cant de ejercitos perdidos por el atacante
			resultadoBatalla.incrementAttackerLostArmy();
		
		++itDef;
		++itAt;
		
	}
	
	return resultadoBatalla;
}

BattleResult Battle::start(ReferenceCountPtr<GameManager>& gameManager){
	
	std::list<int> dadosAtacante;
	std::list<int> dadosDefensor;

	// att que necesito para luego de ejecutar la batalla, se actualice el modelo con el resultado
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisAtacante = map->obtenerPais( this->ataque.getAttackerLand() );
	ReferenceCountPtr<Pais> paisDefensor = map->obtenerPais( this->ataque.getAttackedLand() );	

	ReferenceCountPtr<Player> playerAtacante = game->getPlayer( gameManager->getTurnManager()->getCurrentPlayer() );
	ReferenceCountPtr<Player> playerDefensor = game->getPlayer( gameManager->getTurnManager()->getDefenderPlayer() );


	// tiro los dados para el atacante
	for(int i=0;i<this->ataque.getArmyCount();i++)
		dadosAtacante.push_back(this->dice.roll() );
	
	// tiro los dados para defensor
	for(int j=0;j<this->defensa.getArmyCount();j++)
		dadosDefensor.push_back(this->dice.roll() );
		
	// compara dados de atacante y defensor y obtiene el resultado de la batalla
BattleResult resultadoBatalla = compareDice(dadosAtacante,dadosDefensor,playerAtacante->getColor(),playerDefensor->getColor());	
	
	// actualizacion del modelo con respecto al resultado de la batalla

	// elimina del pais atacante, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisAtacante->removeArmies(resultadoBatalla.getAttackerResult());

	// elimina del pais defensor, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisDefensor->removeArmies(resultadoBatalla.getDefenderResult());


	// verifico si hubo conquista de pais defensor

	// si pais defensor se quedo con cero ejercitos
	if ( paisDefensor->getArmyCount() == 0  ){
		
		cout<<"PAIS CONQUISTADO!!!! BRAVO"<<endl;
			
		//seteo al resultado de la batalla la cant de ejercitos a mover al pais conquistado.
		resultadoBatalla.setConquest( this->defensa.getArmyCount() );
		
		// elimino al pais defensor de la lista de paises del player defensor
		playerDefensor->removeConqueredLand(this->defensa.getDefenderdLand());
		
		// agrego pais conquistado a la lista de paises del jugador atacante
		playerAtacante->addConqueredLand( this->ataque.getAttackerLand() );
				
		// remuevo del pais atacante tantos ejercitos como dados usados en la batalla ( = dant ejercitos defensores )
		// para "moverlos" al pais conquistado.
		paisAtacante->removeArmies( this->defensa.getArmyCount());
		// agrego al pais defensor que fue conquistado por el atacante los ejercitos "movidos"
		paisDefensor->addArmies( this->defensa.getArmyCount() );

		cout<<"EL ATACANTE MOVIO "<<resultadoBatalla.getDefenderResult()<<" ejercitos para conquistar."<<endl;
		cout<<"el pais "<<this->ataque.getAttackerLand()<<"que ataco, se quedo con ejercitos: "<<paisAtacante->getArmyCount()<<endl;
	

		//verifico si hubo conquista de continente a partir de la conquista de un nuevo pais
	
		//  obtengo lista de continentes conquistados, si los hay, a partir de los paises conquistados.
		std::vector<std::string> vecContinentes = game->conformContinent(playerAtacante->getConqueredLandList() );
			
		//veo si la lista de continentes conquistados tiene alguno que no este seteado en los continentes del jugador ( nuevo continente //conquistado.
		for ( unsigned int i=0; i<vecContinentes.size();i++){
			//si playerAtacante no es dueño todavia de uno de los continentes conquistados segun vecContinentes
			if ( !playerAtacante->continentOwner( vecContinentes[i] ) )
				//seteo al continente actual como conquistado por el player atacante
				playerAtacante->addConqueredContinent(vecContinentes[i] );
		}
	
	}


	

	// setearle al battle result 0 1 2 3 para saber si hubo conquista:
/*
	0: no hubo
	1:hubo conquista y hay q "mover" un ejercito al pais que fue conquistado
	2:hubo conquista y hay q "mover" 2 ejercito al pais que fue conquistado


*/


	
	return resultadoBatalla;
	

}

