#ifndef __NOROOM_H__
#define __NOROOM_H__

/**
 * server => client
 */

#include "command.h"
class NoRoom: public Command {
	public:
	NoRoom();
	virtual ~NoRoom();
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(std::string xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
	virtual void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
};

#endif /* __NOROOM_H__*/
