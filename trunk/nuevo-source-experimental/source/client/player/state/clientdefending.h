#ifndef __CLIENTDEFENDING_H__
#define __CLIENTDEFENDING_H__

#include<string>
#include "clientstate.h"
#include "clientwaiting.h"

class ClientDefending: public ClientState {
    /**
     * Atributos privados de la clase ClientDefending.
     */
    private:
        /**
         * Almacena el nombre del pais a defender.
         */
        std::string attackedCountry;
        /**
         * Almacena el Id del jugador atacante.
         */
        int attackerId;
    /**
     * Mètodos publicos de la clase ClientDefending.
     */
    public:
        /**
         * Constructor de la clase ClientDefending.
         */
        ClientDefending(GameWindow& gameWindow, const std::string& attackedCountry, const int& attackerId);
        /**
         * Procesa la seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& country);
        /**
         * Procesa la ejecucion de un comando NoMore (Envia un defend al servidor)
         */
        virtual void executeNoMore();
        /**
         * Destructor virtual de la clase ClientDefending.
         */
        virtual ~ClientDefending();
};

#endif /** __CLIENTDEFENDING_H__ */

