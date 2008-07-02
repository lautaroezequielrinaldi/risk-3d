#ifndef SERVERBATTLERESULT_H_
#define SERVERBATTLERESULT_H_

#include "servercommand.h"
#include "../commands/battleresult.h"

class ServerBattleResult : public BattleResult, public ServerCommand
{
	
	public:
	
		ServerBattleResult();
	
		~ServerBattleResult();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
};

#endif /*SERVERBATTLERESULT_H_*/
