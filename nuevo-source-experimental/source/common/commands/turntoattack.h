#ifndef __TURNTOATTACK_H__
#define __TURNTOATTACK_H__

/**
 * server => client
 *
 * Indicacion del servidor de pasaje a estado Attacking
 */

#include <string>
#include <vector>
#include "command.h"

class TurnToAttack : virtual public Command
{
	
	
	private:
		int numeroJugador;
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		TurnToAttack(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		TurnToAttack(const std::string & xml);
		

		TurnToAttack();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~TurnToAttack();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		
		virtual std::string getName();
		
		/**
		 * 	Notifica que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*__TURNTOATTACK_H__*/
