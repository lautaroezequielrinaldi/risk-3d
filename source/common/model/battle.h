#ifndef BATTLE_H_
#define BATTLE_H_

#include<list>
#include "../commands/attack.h" 
#include "../commands/defend.h"
#include "battleresult.h"
#include "dice.h"

/**
 * Clase que representa a la batalla en el modelo del juego.
 */
class Battle
{
	/**
	 * Atributos privados de la clase
	 */
	private:
	
		/**
		 * Almacena el ataque realizado por el jugador.
		 */
        Attack& ataque;
	
		/**
		 * Almacena la defensa hecha por el jugador
		 */
		Defend& defensa;
		 
		 /**
		  * Almacena el dado con el que se definira el resultado de la batalla.
		  */
		Dice& dice;
		
		
	/**
	 * Metodos publicos de la clase
	 */
	public:
		
		/**
		 * Constructor de la clase
		 */
		//Battle(ReferenceCountPtr<Attack>& ataque,ReferenceCountPtr<Defend>& defensa,ReferenceCountPtr<Dice>&  dice);
		Battle(Attack& ataque,Defend& defensa,Dice& dice);
		/**
		 * Destructor de la clase
		 */
		~Battle();
		
		/**
		 * Metodo cuyo proposito es iniciar la batalla entre atacante y defensor.
		 * Devuelve el resultado de la batalla.
		 */
		BattleResult start(ReferenceCountPtr<GameManager>& gameManager); 
		
	/**
	 * Metodos privados de la clase
	 */
	private:
		
		/**
		 * Metodo cuyo proposito es comparar los dados del atacante con los del defensor para definir la batalla.
		 * Recibe un vector con los dados del atacante , otro con los dados del defensor, el id jugador atacante y el id jugador * *defensor.
		 * Devuelve un objeto Resultado en el cual esta seteado el resultado de la batalla.
		 */
		BattleResult compareDice(std::list<int>attackerDice, std::list<int> defenderDice, int attackerPlayer, int defenderPlayer);
		
};

#endif /*BATTLE_H_*/
