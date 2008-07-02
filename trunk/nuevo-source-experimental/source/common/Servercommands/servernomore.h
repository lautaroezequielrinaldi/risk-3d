#ifndef SERVERNOMORE_H_
#define SERVERNOMORE_H_

#include "../commands/nomore.h"
#include "servercommand.h"

class ServerNoMore : public NoMore, public ServerCommand
{
	public:
		
		ServerNoMore();
        ServerNoMore(const std::string& xml);	
		~ServerNoMore();
	
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERNOMORE_H_*/
