#ifndef SERVERTURNTOATTACK_H_
#define SERVERTURNTOATTACK_H_

#include "../commands/turntoattack.h"
#include "servercommand.h"

class ServerTurnToAttack : public TurnToAttack, public ServerCommand
{
	public:
	
		ServerTurnToAttack();
        ServerTurnToAttack(const std::string& xml);
		~ServerTurnToAttack();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERTURNTOATTACK_H_*/
