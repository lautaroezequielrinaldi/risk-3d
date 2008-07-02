#ifndef __MESSAGEHYDRATOR_H__
#define __MESSAGEHYDRATOR_H__

#include<string>
#include "attack.h"
#include "chat.h"
#include "defend.h"
#include "didiwin.h"
#include "joingame.h"
#include "lose.h"
#include "map.h"
#include "maplist.h"
#include "move.h"
#include "nomore.h"
#include "noroom.h"
#include "populate.h"
#include "quit.h"
#include "readytoplay.h"
#include "selectmap.h"
#include "surrender.h"
#include "turntoattack.h"
#include "turntomove.h"
#include "turntooccupy.h"
#include "win.h"
#include "youare.h"
#include "battleresult.h"
#include "../smartpointer/referencecountptr.h"

class MessageHydrator {
    /**
     * Metodos publicos de la clase MessageHydrator.
     */
    public:
        /**
         * Crea un nuevo mensaje command hidratandolo.
         */
        ReferenceCountPtr<Command> createCommand(const std::string& commandName, const std::string& xml);
        /**
         * Destructor virtual de la clase MessageHydrator.
         */
        virtual ~MessageHydrator();
};

#endif /** __MESSAGEHYDRATOR_H__ */

