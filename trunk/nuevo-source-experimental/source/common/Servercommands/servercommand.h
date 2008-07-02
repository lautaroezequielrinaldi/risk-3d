#ifndef SERVERCOMMAND_H_
#define SERVERCOMMAND_H_

#include "../model/gamemanager.h"

/**
 * Clase cuyo proposito es representar a los comandos del servidor .
 */
 
class ServerCommand
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
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
		
		
};

#endif /*SERVERCOMMAND_H_*/