#ifndef SERVERMOVE_H_
#define SERVERMOVE_H_


#include "servercommand.h"
#include "../commands/move.h"


class ServerMove : public ServerCommand, public Move
{
	
	public:
		
		ServerMove();
        ServerMove(const std::string& xml);	
		~ServerMove();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
};

#endif /*SERVERMOVE_H_*/
