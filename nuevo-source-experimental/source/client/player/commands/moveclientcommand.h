#ifndef __MOVECLIENTCOMMAND_H__
#define __MOVECLIENTCOMMAND_H__

#include "../../../common/commands/move.h"
#include "clientcommand.h"

class MoveClientCommand: public Move, public ClientCommand {
	/**
	 * Metodos publicos de la clase MoveClientCommand.
	 */
	public:
        /**
         * Crea un comando de tipo MoveClientCommand.
         */
        MoveClientCommand(ReferenceCountPtr<Game>& game);
		/**
		 * Ejecuta el comando.
		 */
		virtual void execute();
		/**
		 * Clona al comando.
		 */
		virtual ClientCommand* clone();
		/**
		 * Destructor virtual de la clase MoveClientCommand.
		 */
		virtual ~MoveClientCommand();
};

#endif /** __MOVECLIENTCOMMAND_H__ */

