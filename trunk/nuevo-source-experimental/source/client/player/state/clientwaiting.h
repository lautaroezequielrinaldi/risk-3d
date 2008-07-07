#ifndef __CLIENTWAITING_H__
#define __CLIENTWAITING_H__

#include "clientstate.h"

class ClientWaiting: public ClientState {
    /**
     * Mètodos publicos de la clase ClientWaiting.
     */
    public:
        /**
         * Constructor de la clase ClientWaiting.
         */
        ClientWaiting(GameWindow& gameWindow);
        /**
         * Procesa la seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& country);
        /**
         * Destructor virtual de la clase ClientWaiting.
         */
        virtual ~ClientWaiting();
};

#endif /** __CLIENTWAITING_H__ */

