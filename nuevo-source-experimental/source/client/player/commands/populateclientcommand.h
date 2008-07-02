#ifndef __POPULATECLIENTCOMMAND_H__
#define __POPULATECLIENTCOMMAND_H__

#include "clientcommand.h"

class PopulateClientCommand: public ClientCommand {

	/**
	 * Metodos publicos de la clase PopulateClientCommand.
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
		 * Destructor virtual de la clase PopulateClientCommand.
		 */
		virtual ~PopulateClientCommand();
};

#endif /** __POPULATECLIENTCOMMAND_H__ */

