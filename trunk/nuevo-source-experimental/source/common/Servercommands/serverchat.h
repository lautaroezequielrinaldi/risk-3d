#ifndef SERVERCHAT_H_
#define SERVERCHAT_H_

#include "../commands/chat.h"
#include "servercommand.h"

class ServerChat : public Chat, public ServerCommand
{
	public:
	
		ServerChat();
	
		~ServerChat();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);				
};

#endif /*SERVERCHAT_H_*/
