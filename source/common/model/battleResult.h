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
	 	
	 	/*cantidad de ejercitos del atacante, ganados o perdidos en la batalla.
	 	 * Puede ser un numero positivo o negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoAtacante;
	
		/*cantidad de ejercitos del defensor, ganados o perdidos en la batalla.
	 	 * Puede ser un numero positivo o negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoDefensor;
		
	/**
	 * Metodos publicos de la clase
	 */
	public:
		
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
		std::string& getAttackerLand();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del adefensor.
		 */		
		std::string& getDefenderLand();
		
		/**
		 * Metodo cuyo proposito es obtener el resultado del atacante.
		 */
		int getAttackerResult();
		
		/**
		 * Metodo cuyo proposito es obtener el resultado del defensor.
		 */
		int getDefenderResult();
		
		/**
		 * Metodo cuyo proposito es establecer el nombre del atacante
		 */
		void setAttackerLand(std::string& attackerLando);
		
		/**
		 * Metodo cuyo proposito es establecer el nombre del defensor.
		 */		
		void setDefenderLand(std::string& defenderLand);
		
		/**
		 * Metodo cuyo proposito es establecer el resultado del atacante en la batalla
		 */
		void setAttackerResult(int attackerResult);

		/**
		 * Metodo cuyo proposito es establecer el resultado del defensor en la batalla
		 */		
		void setDefenderResult(int defnderResult);
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar un archivo XML y construir un objeto a partir de el.
		 */
		void* hydrate(std::string fileName) ;
};

#endif /*BATTLERESULT_H_*/
