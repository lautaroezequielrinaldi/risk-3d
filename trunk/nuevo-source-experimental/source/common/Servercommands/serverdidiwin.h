#ifndef SERVERDIDIWIN_H_
#define SERVERDIDIWIN_H_

#include "../commands/didiwin.h"
#include "servercommand.h"

class ServerDidIWin : public DidIWin, public ServerCommand
{
	public:
	
		ServerDidIWin();
        ServerDidIWin(const std::string& xml);	
		~ServerDidIWin();
		
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERDIDIWIN_H_*/
