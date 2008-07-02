#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include "../commands/map.h"
#include "servercommand.h"

class ServerMap : public Map, public ServerCommand
{
	public:
	
		ServerMap();
        ServerMap(const std::string& xml);	
		~ServerMap();
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERMAP_H_*/
