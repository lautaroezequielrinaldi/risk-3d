#ifndef __CLIENTMOVING_H__
#define __CLIENTMOVING_H__

#include "clientstate.h"
#include "clientwaiting.h"

class ClientMoving: public ClientState {
    /**
     * Atributos privados de la clase ClientMoving.
     */
    private:

    /**
     * Metodos publicos de la clase ClientMoving.
     */
    public:
        /**
         * Constructor de la clase ClientMoving.
         */
        ClientMoving(GameWindow& gameWindow);
        /**
         * Procesa seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& country);
        /**
         * Destructor de la clase ClientMoving.
         */
        virtual ~ClientMoving();
};

#endif /** __CLIENTMOVING_H__ */

