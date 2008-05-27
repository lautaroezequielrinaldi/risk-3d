#ifndef BATTLE_H_
#define BATTLE_H_

#include<vector>
#include "../commands/attack.h" 
#include "../commands/defend.h"
#include "battleResult.h"

/**
 * Clase que representa a la batalla en el modelo del juego.
 */
class Battle
{
	/**
	 * Atributos privados de la clase
	 */
	private:
	
		/*referencia al ataque realizado por el jugador*/
		Attack& ataque;
	
		/*referencia a la defensa hecha por el jugador*/
		Defend& defensa;
		 
		/*objeto que se encargara de almacenar el resultado de la batalla*/
		BattleResult resultadoBatalla;
		
	/**
	 * Metodos publicos de la clase
	 */
	public:
		
		/**
		 * Constructor de la clase
		 */
		Battle(Attack& ataque,Defend& defensa);
		
		/**
		 * Destructor de la clase
		 */
		~Battle();
		
		/**
		 * Metodo cuyo proposito es iniciar la batalla entre atacante y defensor.
		 * Devuelve el resultado de la batalla.
		 */
		BattleResult& start(); 
		
	/**
	 * Metodos privados de la clase
	 */
	private:
		
		/**
		 * Metodo cuyo proposito es simular la tirada de dados al azar.
		 * Devuelve el numero de dado que se obtuvo.
		 */
		int rollDice();
		
		/**
		 * Metodo cuyo proposito es comparar los dados del atacante con los del defensor para definir la batalla.
		 * Recibe un vector con los dados del atacante y otro con los dados del defensor.
		 * Devuelve un objeto Resultado en el cual esta seteado el resultado de la batalla.
		 */
		 BattleResult& compareDice(std::vector<int>attackerDice, std::vector<int> defenderDice);
		
};

#endif /*BATTLE_H_*/
