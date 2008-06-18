#ifndef FILEDICE_H_
#define FILEDICE_H_

#include "dice.h"
#include <fstream>
#include <vector>

/**
 * Clase cuyo proposito es representar a un dado del juego que tomara su valor desde un archivo de texto.
 * Formato valido del archivo de texto:
 * 										- linea 1: valores de los dados del atacante ( hasta 3 ) separados por comas.
 * 										- linea 2: valores de los dados del defensor ( hasta 2 ) separados por comas.
 */

class FileDiceBattle : public Dice
{

	private:
	
		std::ifstream file;
		
		std::vector<int> dadosAtacante;
		
		std::vector<int> dadosDefensor;
		
		unsigned int posicionADevolverAt;
		
		unsigned int posADevolverDef;
		
		bool atacante;

	public:
	
		/**
	 	 * Constructor de la clase.
	 	 */
		FileDiceBattle(std::string fileName);
		
		/**
	 	 * Destructor de la clase.
	 	 */
		~FileDiceBattle();
		
		/**
		 * Metodo cuyo proposito es simular la tirada de dados.
		 * Devuelve un numero de dado que se obtiene de un archivo.
		 * La devolucion respeta el orden de aparicion de los valores en el archivo.
		 */
		int roll();
		
	private:
	
		/**
		 * Metodo cuyo proposito es cargar los vectores de valores de los dados desde el archivo
		 */
		 void loadDiceValue();
		
		
};

#endif /*FILEDICE_H_*/
