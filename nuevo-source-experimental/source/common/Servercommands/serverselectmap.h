#ifndef SERVERSELECTMAP_H_
#define SERVERSELECTMAP_H_

#include "../commands/selectmap.h"
#include "servercommand.h"

class ServerSelectMap : public SelectMap, public ServerCommand
{

	public:
	
		ServerSelectMap();
		ServerSelectMap(const std::string& xml);
		~ServerSelectMap();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERSELECTMAP_H_*/
