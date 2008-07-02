#ifndef __MOVECLIENTCOMMAND_H__
#define __MOVECLIENTCOMMAND_H__

#include "clientcommand.h"

class MoveClientCommand: public ClientCommand {
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
		 * Devuelve el tipo de comando.
		 */
		virtual std::string getType();
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

