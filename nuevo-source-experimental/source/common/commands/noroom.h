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


		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /* __NOROOM_H__*/
