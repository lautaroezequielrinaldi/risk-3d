#ifndef SERVERDEFEND_H_
#define SERVERDEFEND_H_

#include "servercommand.h"
#include "../commands/defend.h"

class ServerDefend : public ServerCommand, public Defend
{
	
	public:
		
		ServerDefend();
		
		~ServerDefend();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
		
};

#endif /*SERVERDEFEND_H_*/
