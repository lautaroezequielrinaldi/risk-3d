#ifndef RANDOMDICE_H_
#define RANDOMDICE_H_

#include "dice.h"

class RandomDice : public Dice
{

	public:
	
	
		/**
	 	 * Constructor de la clase.
	 	 */
		RandomDice();
		
		/**
		 * Destructor de la clase.
	 	 */
		~RandomDice();
		
		/**
		 * Metodo cuyo proposito es simular la tirada de dados.
		 * Devuelve el numero aleatorio de dado que se obtuvo.
		 */
		int roll();
		
		int roll(int maxLimit);
};

#endif /*RANDOMDICE_H_*/
