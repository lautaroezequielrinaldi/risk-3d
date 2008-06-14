#ifndef FILEDICE_H_
#define FILEDICE_H_

#include "dice.h"

class FileDice : public Dice
{

	public:
	
		/**
	 	 * Constructor de la clase.
	 	 */
		FileDice();
		
		/**
	 	 * Destructor de la clase.
	 	 */
		~FileDice();
		
		/**
		 * Metodo cuyo proposito es simular la tirada de dados.
		 * Devuelve un numero de dado que se obtiene de un archivo.
		 */
		int roll();
		
};

#endif /*FILEDICE_H_*/
