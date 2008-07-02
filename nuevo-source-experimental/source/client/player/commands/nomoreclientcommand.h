#ifndef __NOMORECLIENTCOMMAND_H__
#define __NOMORECLIENTCOMMAND_H__

#include "clientcommand.h"

class NoMoreClientCommand: public ClientCommand {

	/**
	 * Metodos publicos de la clase NoMoreClientCommand.
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
		 * Destructor virtual de la clase NoMoreClientCommand.
		 */
		virtual ~NoMoreClientCommand();
};

#endif /** __NOMORECLIENTCOMMAND_H__ */

