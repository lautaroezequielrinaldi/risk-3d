#ifndef BATTLERESULT_H_
#define BATTLERESULT_H_

#include "command.h"

/**
 * Clase que representa el resultado de una batalla dentro del modelo del juego
 */
class BattleResult : virtual public Command
{
	
	/**
	 * Atributos privados de la clase
	 */
	 private:
	 
	 	/*nombre del pais atacante*/
	 	std::string paisAtacante;
	 	
	 	/*nombre del pais defensor*/
	 	std::string paisDefensor;
	 	
		/* color jugador atacante*/
		int jugadorAtacante;
	
		/* color jugador defensor*/
		int jugadorDefensor;

	 	/*cantidad de ejercitos perdidos del atacante en la batalla.
	 	 * Puede ser un numero  negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoAtacante;
	
		/*cantidad de ejercitos perdidos del defensor en la batalla.
	 	 * Puede ser un numero negativo en caso que haya perdido ejercitos
	 	 */
	 	int resultadoDefensor;

		/**
		 * Almacena:
		 *           0 sino hubo conquista.
		 * 	     1 si hubo conquista y hay que mover 1 ejercito al pais conquistado.
		 * 	     2 si hubo conquista y hay que mover 2 ejercitos al pais conquistado.
		 */
		int conquista;
		
	/**
	 * Metodos publicos de la clase
	 */
	public:
		
		/**
		 * Constructor de la clase
		 */
		BattleResult(  std::string  attackerLand , std::string  defenderLand, int jugadorAtacante, int jugadorDefensor);

		/**
		 * Constructor de la clase
		 */	
		BattleResult();
        /**
         * Constructor de la clase
         */
        BattleResult(const std::string& xml);	
		/**
		 * Destructor de la clase
		 */
		~BattleResult();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais atacante.
		 */
		std::string getAttackerLand();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais defensor.
		 */		
		std::string getDefenderLand();

		/**
		 * Metodo cuyo proposito es obtener el color del atacante.
		 */		
		int getAttackercolor();

		/**
		 * Metodo cuyo proposito es obtener el color del adefensor.
		 */		
		int getDefenderColor();

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
		void incrementAttackerLostArmy();

		/**
		 * Metodo cuyo proposito es eliminar un ejercito del pais defensor.
		 */		
		void incrementDefenderLostArmy();
		
		/**
		 * Metodo cuyo proposito es establecer si hubo o no conquista luego de una batalla, y la cantidad de ejercitos
		 * que se debera mover al pais conquistado.
		 */
		void setConquest ( int armyCount );

		/**
		 * Metodo cuyo proposito es informar si hubo una conquista luego de una batalla.
 		 *       0 sino hubo conquista.
		 * 	     1 si hubo conquista y hay que mover 1 ejercito al pais conquistado.
		 * 	     2 si hubo conquista y hay que mover 2 ejercitos al pais conquistado.
		 */
		 int getConquest();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar un objeto a partir de un archivo XML.
		 */
		void* hydrate(const std::string & xml) ;

		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*BATTLERESULT_H_*/

