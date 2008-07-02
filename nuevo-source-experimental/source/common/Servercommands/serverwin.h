#ifndef SERVERWIN_H_
#define SERVERWIN_H_

#include "servercommand.h"
#include "../commands/win.h"

class ServerWin : public ServerCommand, public Win
{
	
	public:
	
		ServerWin();
        ServerWin(const std::string& xml);	
		~ServerWin();
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERWIN_H_*/
