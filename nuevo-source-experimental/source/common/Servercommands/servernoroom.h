#ifndef SERVERNOROOM_H_
#define SERVERNOROOM_H_

#include "servercommand.h"
#include "../commands/noroom.h"

class ServerNoRoom : public ServerCommand, public NoRoom
{
	public:
	
		ServerNoRoom();
        ServerNoRoom(const std::string& xml);		
		~ServerNoRoom();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERNOROOM_H_*/
