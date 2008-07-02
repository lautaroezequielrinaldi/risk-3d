#ifndef SERVERQUIT_H_
#define SERVERQUIT_H_

#include "servercommand.h"
#include "../commands/quit.h"

class ServerQuit : public ServerCommand, public Quit
{
	public:
		
		ServerQuit();
	
		~ServerQuit();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);			
};

#endif /*SERVERQUIT_H_*/
