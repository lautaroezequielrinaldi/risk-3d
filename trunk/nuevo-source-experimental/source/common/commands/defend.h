#ifndef DEFEND_H_
#define DEFEND_H_

/**
 * client => server
 *
 * Comando creado por el cliente, se envia al servidor para su validacion y utilizacion en Battle,
 * este luego hace los Kill, SetOwner y Move correspondientes
 */

#include <vector>
#include "command.h"

class Defend : virtual public Command
{
	
	private:
	
		std::string paisDefensor;
		int cantidadEjercitos;

		int jugadorAtacante;
		int jugadorDefensor;
	
	public:
		
		/*
		 * Constructor de la clase
		 */
		Defend(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Defend(const std::string &xml);

		Defend();
		
		/*
		 * Destructor de la clase
		 */
		virtual ~Defend();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string &xml);
		
		virtual std::string getName();

		std::string getDefenderdLand();
		
		int getArmyCount();

		/**
		 * Metodo cuyo proposito es obtener el codigo del jugador atacante
		 */
		int getAttackerId();

		/**
		 * Metodo cuyo proposito es obtener el codigo del jugador atacado.
		 */
		int getAttackedId();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);		
};	

#endif /*DEFEND_H_*/


