
#include "battle.h"
#include<stdlib.h>
#include<vector>


Battle::Battle(Attack& ataque,Defend& defensa): ataque (ataque ), defensa(defensa)
{
}

Battle::~Battle()
{
	// no realiza ninguna accion
}

int Battle::rollDice(){
	
	int dado;
	
	// repito el pedido de numero aleatorio hasta que sea distinto de cero.
	do{
		// pido un numero aleatorio
		dado = random();
		
		// aplico mod 6 al numero devuelto por random para que me devuelva un numero entre 1 y 6.
		dado = dado % 6;
	
	}while (dado == 0);
	
	return dado;
}

BattleResult& Battle::compareDice(std::vector<int>attackerDice, std::vector<int> defenderDice){
	
}

BattleResult Battle::start(){

	BattleResult result;
	std::vector<int> dadosAtacante;
	std::vector<int> dadosDefensor;
	
	// tiro los dados para el atacante
	for(int i=0;i<this->ataque.getArmyCount();i++)
		dadosAtacante[i] = rollDice();
	
	// tiro los dados para defensor
	for(int j=0;j<this->ataque.getArmyCount();j++)
		dadosAtacante[j] = rollDice();
		
	// compara dados de atacante y defensor y obtiene el resultado de la batalla
	result = compareDice(dadosAtacante, dadosDefensor);	
	
	return result;
	

}

