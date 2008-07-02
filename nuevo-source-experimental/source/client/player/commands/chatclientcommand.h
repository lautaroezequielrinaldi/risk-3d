#ifndef __CHATCLIENTCOMMAND_H__
#define __CHATCLIENTCOMMAND_H__

#include "clientcommand.h"

class ChatClientCommand: public ClientCommand {

	/**
	 * Metodos publicos de la clase ChatClientCommand.
	 */
	public:
		/**
		 * Ejecuta el comando.
		 */
		virtual void execute();
		/**
		 * Devuelve el tipo de comando.
		 */
		virtual std::string getType();
		/**
		 * Clona al comando.
		 */
		virtual ClientCommand* clone();
		/**
		 * Destructor virtual de la clase ChatClientCommand.
		 */
		virtual ~ChatClientCommand();
};

#endif /** __CHATCLIENTCOMMAND_H__ */

