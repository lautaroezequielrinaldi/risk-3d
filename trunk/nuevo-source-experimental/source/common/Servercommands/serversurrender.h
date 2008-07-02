#ifndef SERVERSURRENDER_H_
#define SERVERSURRENDER_H_

#include "servercommand.h"
#include "../commands/surrender.h"

class ServerSurrender : public ServerCommand, public Surrender
{
	public:
	
		ServerSurrender();
		
		~ServerSurrender();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);				
};

#endif /*SERVERSURRENDER_H_*/
