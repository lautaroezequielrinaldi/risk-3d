#ifndef SERVERLOSE_H_
#define SERVERLOSE_H_

#include "servercommand.h"
#include "../commands/lose.h"

class ServerLose : public ServerCommand, public Lose
{
	public:
	
		ServerLose();
        ServerLose(const std::string& xml);	
		virtual ~ServerLose();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERLOSE_H_*/
