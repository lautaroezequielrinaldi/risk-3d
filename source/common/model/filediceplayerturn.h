#ifndef FILEDICEPLAYERTURN_H_
#define FILEDICEPLAYERTURN_H_

#include "dice.h"

/**
 * Clase cuyo proposito es representar a un dado del juego que tomara 1 solo valor desde un archivo de texto.
 * Se utilizara para obtener el numero de jugador que comenzara la ronda.
 */

class fileDicePlayerTurn : public Dice
{
	public:

		/**
	 	 * Constructor de la clase.
	 	 */	
		fileDicePlayerTurn();
		
		/**
	 	 * Destructor de la clase.
	 	 */
		~fileDicePlayerTurn();

		/**
		 * Metodo cuyo proposito es simular la tirada de dados.
		 * Devuelve un numero de dado que se obtiene de un archivo.
		 * La devolucion respeta el orden de aparicion de los valores en el archivo.
		 */
		int roll();
		
};

#endif /*FILEDICEPLAYERTURN_H_*/
