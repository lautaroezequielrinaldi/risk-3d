#ifndef __ATTACKCLIENTCOMMAND_H__
#define __ATTACKCLIENTCOMMAND_H__

#include "clientcommand.h"

class AttackClientCommand: public ClientCommand {

	/**
	 * Metodos publicos de la clase AttackClientCommand.
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
		 * Destructor virtual de la clase AttackClientCommand.
		 */
		virtual ~AttackClientCommand();
};

#endif /** __ATTACKCLIENTCOMMAND_H__ */

