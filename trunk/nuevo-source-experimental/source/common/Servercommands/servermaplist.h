#ifndef SERVERMAPLIST_H_
#define SERVERMAPLIST_H_

#include "servercommand.h"
#include "../commands/maplist.h"

class ServerMapList : public ServerCommand, public MapList
{
	public:
	
		ServerMapList();
		
		~ServerMapList();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		
};

#endif /*SERVERMAPLIST_H_*/
