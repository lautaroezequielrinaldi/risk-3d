#ifndef __CLIENTPOPULATING_H__
#define __CLIENTPOPULATING_H__

#include "clientstate.h"

class ClientPopulating: public ClientState {
    /**
     * Mètodos pùblicos de la clase ClientPopulating.
     */
    public:
        /**
         * Constructor de la clase ClientPopulating.
         */
        ClientPopulating(GameWindow& gameWindow);
        /**
         * Procesa la seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& country);
        /**
         * Destructor virtual de la clase ClientPopulating.
         */
        virtual ~ClientPopulating();
};

#endif /** __CLIENTPOPULATING_H__ */

