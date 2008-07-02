#ifndef SERVERTURNTOPOPULATE_H_
#define SERVERTURNTOPOPULATE_H_

#include "servercommand.h"
#include "../commands/turntopopulate.h"

class ServerTurnToPopulate : public TurnToPopulate , public ServerCommand
{
	public:
	
		ServerTurnToPopulate();
		
		~ServerTurnToPopulate();
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERTURNTOPOPULATE_H_*/
