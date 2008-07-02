#ifndef SERVERTURNTOOCCUPY_H_
#define SERVERTURNTOOCCUPY_H_

#include "servercommand.h"
#include "../commands/turntooccupy.h"

class ServerTurnToOccupy : public ServerCommand, public TurnToOccupy
{
	public:
	
		ServerTurnToOccupy();
		
		~ServerTurnToOccupy();
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERTURNTOOCCUPY_H_*/
