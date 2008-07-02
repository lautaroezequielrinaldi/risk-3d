#ifndef SERVERTURNTOMOVE_H_
#define SERVERTURNTOMOVE_H_

#include "../commands/turntomove.h"
#include "servercommand.h"

class ServerTurnToMove : public TurnToMove, public ServerCommand
{
	public:
	
		ServerTurnToMove();
        ServerTurnToMove(const std::string& xml);		
		~ServerTurnToMove();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERTURNTOMOVE_H_*/
