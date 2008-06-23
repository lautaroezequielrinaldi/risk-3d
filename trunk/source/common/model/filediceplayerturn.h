#ifndef FILEDICEPLAYERTURN_H_
#define FILEDICEPLAYERTURN_H_

#include "dice.h"
#include <fstream>

/**
 * Clase cuyo proposito es representar a un dado del juego que tomara 1 solo valor desde un archivo de texto.
 * Se utilizara para obtener el numero de jugador que comenzara la ronda.
 */

class FileDicePlayerTurn : public Dice
{
	
	private:
	
		/**
		 * Objeto que manejara el archivo de entrada que contendra el valor del dado.
		 */
		std::ifstream file;
	
	public:

		/**
	 	 * Constructor de la clase.
	 	 */	
		FileDicePlayerTurn(std::string fileName);
		
		/**
	 	 * Destructor de la clase.
	 	 */
		~FileDicePlayerTurn();

		/**
		 * Metodo cuyo proposito es simular la tirada de dados.
		 * Devuelve un numero de dado que se obtiene de un archivo.
		 * Solo podra invocarse una vez por instancia.
		 */
		int roll();
		
};

#endif /*FILEDICEPLAYERTURN_H_*/
