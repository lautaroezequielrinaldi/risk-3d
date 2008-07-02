#ifndef __POPULATECLIENTCOMMAND_H__
#define __POPULATECLIENTCOMMAND_H__

#include "../../../common/commands/populate.h"
#include "clientcommand.h"

class PopulateClientCommand: public Populate, public ClientCommand {

	/**
	 * Metodos publicos de la clase PopulateClientCommand.
	 */
	public:
        /**
         * Constructor de la clase PopulateClientCommand.
         */
        PopulateClientCommand(ReferenceCountPtr<Game>& game);
		/**
		 * Ejecuta el comando.
		 */
		virtual void execute();
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

