#ifndef SERVERYOUARE_H_
#define SERVERYOUARE_H_

#include "../commands/youare.h"
#include "servercommand.h"

class ServerYouAre : public YouAre, public ServerCommand
{
	public:
	
		ServerYouAre();
        ServerYouAre(const std::string& xml);	
		~ServerYouAre();
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERYOUARE_H_*/
