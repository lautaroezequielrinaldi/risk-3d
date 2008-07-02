#ifndef __SURRENDERCLIENTCOMMAND_H__
#define __SURRENDERCLIENTCOMMAND_H__

#include "../../../common/commands/surrender.h"
#include "clientcommand.h"

class SurrenderClientCommand: public Surrender, public ClientCommand {
    /**
     * Metodos privados de la clase SurrenderClientCommand.
     */
    public:
        /**
         * Constructor de la clase SurrenderClientCommand.
         */
        SurrenderClientCommand(ReferenceCountPtr<Game>& game);
        /**
         * Clona al comando.
         */
        virtual ClientCommand* clone();
        /**
         * Ejecuta al comando.
         */
        void execute();
        /**
         * Destructor virtual de la clase SurrenderClientCommand.
         */
        virtual ~SurrenderClientCommand();
};

#endif /** __SURRENDERCLIENTCOMMAND_H__ */

