#ifndef __QUITCLIENTCOMMAND_H__
#define __QUITCLIENTCOMMAND_H__

#include "../../../common/commands/quit.h"
#include "clientcommand.h"

class QuitClientCommand: public Quit, public ClientCommand {
    /**
     * Metdos publicos de la clase QuitClientCommand.
     */
    public:
        /**
         * Constructor de la clase QuitClientCommand.
         */
        QuitClientCommand(ReferenceCountPtr<Game>& game);
        /**
         * Ejecuta el comando.
         */
        virtual void execute();
        /**
         * Clona al comando.
         */
        virtual ReferenceCountPtr<ClientCommand> clone();
        /**
         * Destructor virtual de la clase QuitClientCommand.
         */
        virtual ~QuitClientCommand();
};

#endif /** __QUITCLIENTCOMMAND_H__ */

