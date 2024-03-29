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
		// gana defensor por dado mas alto o por empate ( el defensor siempre se ve favorecido en esa situacion)
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

	cerr<<"Tirando dados para el atacante....."<<endl;	

	// tiro los dados para el atacante
	for(int i=0;i<this->ataque.getArmyCount();i++)
		dadosAtacante.push_back(this->dice.roll() );
	
	cerr<<"Tirando dados para el defensor....."<<endl;
	
	// tiro los dados para defensor
	for(int j=0;j<this->defensa.getArmyCount();j++)
		dadosDefensor.push_back(this->dice.roll() );
		
	cerr<<"Iniciando comparacion de dados del atacante - defensor ....."<<endl;
	
	// compara dados de atacante y defensor y obtiene el resultado de la batalla
	BattleResult resultadoBatalla = compareDice(dadosAtacante,dadosDefensor,playerAtacante->getColor(),playerDefensor->getColor());	
	
	// actualizacion del modelo con respecto al resultado de la batalla
	cerr<<"Actualizando modelo al terminar batalla....."<<endl;

	cerr<<"Removiendo "<< resultadoBatalla.getAttackerResult()<<" armadas perdidas del atacante....."<<endl;
	// elimina del pais atacante, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisAtacante->removeArmies(resultadoBatalla.getAttackerResult());

	cerr<<"Removiendo "<< resultadoBatalla.getDefenderResult()<<" armadas perdidas del defensor....."<<endl;
	// elimina del pais defensor, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisDefensor->removeArmies(resultadoBatalla.getDefenderResult());

	
	// verifico si hubo conquista de pais defensor
	cerr<<"Verificando si hubo conquista....."<<endl;
	
	// si pais defensor se quedo con cero ejercitos
	if ( paisDefensor->getArmyCount() == 0  ){
		
		cerr<<"Se conquisto el pais atacado....."<<endl;
			
		//seteo al resultado de la batalla la cant de ejercitos a mover al pais conquistado.
		resultadoBatalla.setConquest( this->defensa.getArmyCount() );
		
		// elimino al pais defensor de la lista de paises del player defensor
		cerr<<"Eliminando paises del defensor de la lista de paises conquistados....."<<endl;
		std::string defLand = this->defensa.getDefenderdLand();
		playerDefensor->removeConqueredLand(defLand);
		
		// agrego pais conquistado a la lista de paises del jugador atacante
		cerr<<"Agregando a la lista de paises del atacante, el pais conquistado....."<<endl;
		playerAtacante->addConqueredLand(defLand );
				
		// remuevo del pais atacante tantos ejercitos como dados usados en la batalla ( = dant ejercitos defensores )
		// para "moverlos" al pais conquistado.
		cerr<<"Removiendo "<< this->defensa.getArmyCount() << " ejercitos del pais atacante para moverlos al conquistado....."<<endl;
		paisAtacante->removeArmies( this->defensa.getArmyCount());
		
		// agrego al pais defensor que fue conquistado por el atacante los ejercitos "movidos"
		cerr<<"Agregando ejercitos en el pais conquistado....."<<endl;
		paisDefensor->addArmies( this->defensa.getArmyCount() );


		//verifico si hubo conquista de continente a partir de la conquista de un nuevo pais
		cerr<<"Verificando si hubo conquista de continente....."<<endl;
			
		//  obtengo lista de continentes conquistados, si los hay, a partir de los paises conquistados.
		std::vector<std::string> vecContinentes = game->conformContinent(playerAtacante->getConqueredLandList() );
			
		//veo si la lista de continentes conquistados tiene alguno que no este seteado en los continentes del jugador ( nuevo continente //conquistado.
		for ( unsigned int i=0; i<vecContinentes.size();i++){
			//si playerAtacante no es dueño todavia de uno de los continentes conquistados segun vecContinentes
			if ( !playerAtacante->continentOwner( vecContinentes[i] ) ){
				
				cerr<<"Agregando nuevo continente conquistado: " << vecContinentes[i] <<" a la lista de continentes conquistados del atacante....."<<endl;
					
				//seteo al continente actual como conquistado por el player atacante
				playerAtacante->addConqueredContinent(vecContinentes[i] );
			}
		}
	
	}


	return resultadoBatalla;

}

