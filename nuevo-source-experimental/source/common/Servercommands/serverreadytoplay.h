#ifndef SERVERREADYTOPLAY_H_
#define SERVERREADYTOPLAY_H_

#include "../commands/readytoplay.h"
#include "servercommand.h"

class ServerReadyToPlay : public ReadyToPlay, public ServerCommand
{
	public:
	
		ServerReadyToPlay();
        ServerReadyToPlay(const std::string& xml);			
		~ServerReadyToPlay();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERREADYTOPLAY_H_*/
