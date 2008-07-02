#ifndef __DEFENDCLIENTCOMMAND_H__
#define __DEFENDCLIENTCOMMAND_H__

#include "clientcommand.h"

class DefendClientCommand: public ClientCommand {

	/**
	 * Metodos publicos de la clase DefendClientCommand.
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
		 * Destructor virtual de la clase DefendClientCommand.
		 */
		virtual ~DefendClientCommand();
};

#endif /** __DEFENDCLIENTCOMMAND_H__ */

