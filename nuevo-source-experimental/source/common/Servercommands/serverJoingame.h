#ifndef SERVERJOINGAME_H_
#define SERVERJOINGAME_H_

#include "servercommand.h"
#include "../commands/joingame.h"

class ServerJoinGame : public ServerCommand, public JoinGame
{
	public:
	
		ServerJoinGame();
        ServerJoinGame(const std::string& xml);	
		~ServerJoinGame();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERJOINGAME_H_*/
