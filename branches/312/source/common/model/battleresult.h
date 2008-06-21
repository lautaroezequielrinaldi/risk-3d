#ifndef BATTLERESULT_H_
#define BATTLERESULT_H_

#include "../parser/serializable.h"

/**
 * Clase que representa el resultado de una batalla dentro del modelo del juego
 */
class BattleResult : public Serializable
{
	
	/**
	 * Atributos privados de la clase
	 */
	 private:
	 
	 	/*nombre del pais atacante*/
	 	std::string paisAtacante;
	 	
	 	/*nombre del pais defensor*/
	 	std::string paisDefensor;
	 	
	 	/*cantidad de ejercitos perdidos del atacante en la batalla.
	 	 * Puede ser un numero  negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoAtacante;
	
		/*cantidad de ejercitos perdidos del defensor en la batalla.
	 	 * Puede ser un numero negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoDefensor;
		
	/**
	 * Metodos publicos de la clase
	 */
	public:
		
		/**
		 * Constructor de la clase
		 */
		BattleResult(std::string attackerLand ,std::string defenderLand);

		/**
		 * Constructor de la clase
		 */	
		BattleResult();
	
		/**
		 * Destructor de la clase
		 */
		~BattleResult();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del atacante.
		 */
		std::string getAttackerLand();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del adefensor.
		 */		
		std::string getDefenderLand();
		
		/**
		 * Metodo cuyo proposito es obtener el resultado del atacante.
		 */
		int getAttackerResult();
		
		/**
		 * Metodo cuyo proposito es obtener el resultado del defensor.
		 */
		int getDefenderResult();
				
		/**
		 * Metodo cuyo proposito es elminar un ejercito del pais atacante.
		 */
		void deletetAttackerArmy();

		/**
		 * Metodo cuyo proposito es eliminar un ejercito del pais defensor.
		 */		
		void deletetDefenderArmy();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar un objeto a partir de un archivo XML.
		 */
		void* hydrate(std::string fileName) ;
};

#endif /*BATTLERESULT_H_*/
