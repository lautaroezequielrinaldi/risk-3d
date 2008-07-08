#ifndef __CLIENTATTACKING_H__
#define __CLIENTATTACKING_H__

#include "clientstate.h"
#include "clientwaiting.h"

class ClientAttacking: public ClientState {
    /**
     * Atributos privados de la clase ClientAttacking.
     */
    private:

    /**
     * Metodos publicos de la clase ClientAttacking.
     */
    public:
        /**
         * Constructor de la clase ClientAttacking.
         */
        ClientAttacking(GameWindow& gameWindow);
        /**
         * Procesa seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& country);
        /**
         * Destructor de la clase ClientAttacking.
         */
        virtual ~ClientAttacking();
};

#endif /** __CLIENTATTACKING_H__ */

