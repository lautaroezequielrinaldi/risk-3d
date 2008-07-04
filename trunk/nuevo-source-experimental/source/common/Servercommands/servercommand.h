#ifndef SERVERCOMMAND_H_
#define SERVERCOMMAND_H_

#include "../commands/command.h"
#include "../model/gamemanager.h"

/**
 * Clase cuyo proposito es representar a los comandos del servidor .
 */
 
class ServerCommand: virtual public Command
{
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		ServerCommand();
		
		/**
		 * Destructor de la clase
		 */
		virtual ~ServerCommand();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager)=0;
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state)=0;		
		
		
};

#endif /*SERVERCOMMAND_H_*/
