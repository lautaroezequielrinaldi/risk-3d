#ifndef ATTACK_H_
#define ATTACK_H_

/**
 * client => server => client
 *
 * Comando creado en el cliente, se valida en el servidor y se reenvia a todos
 * El atacado pregunta isForMe para pasar al estado Defending
 */

#include <string>
#include <vector>
#include "command.h"

class Attack : virtual public Command
{
	
	private:
	
		std::string paisAtacante;
		std::string paisAtacado;
		int cantidadEjercitos;

		int jugadorAtacante;
		int jugadorDefensor;
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		Attack(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Attack(const std::string & xml);
		

		Attack();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~Attack();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string & xml);
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del comando.
		 */
		virtual std::string getName();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais atacante.
		 */
		std::string getAttackerLand();
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais atacado.
		 */
		std::string getAttackedLand();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos con los que se esta atacando.
		 */
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

#endif /*ATTACK_H_*/
