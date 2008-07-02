#ifndef __BATTLERESULTCLIENTCOMMAND_H__
#define __BATTLERESULTCLIENTCOMMAND_H__

#include "../../../common/commands/battleresult.h"
#include "clientcommand.h"
#include "../../../common/model/mapa.h"


class BattleResultClientCommand: public BattleResult, public ClientCommand {

	/**
	 * Metodos publicos de la clase BattleResultClientCommand.
	 */
	public:
        /**
         * Constructor de la clase BattleResultClientCommand.
         */
        BattleResultClientCommand(ReferenceCountPtr<Game>& game);
		/**
		 * Ejecuta el comando.
		 */
		virtual void execute();
		/**
		 * Clona al comando.
		 */
		virtual ReferenceCountPtr<ClientCommand> clone();
		/**
		 * Destructor virtual de la clase BattleResultClientCommand.
		 */
		virtual ~BattleResultClientCommand();
};

#endif /** __BATTLERESULTCLIENTCOMMAND_H__ */

