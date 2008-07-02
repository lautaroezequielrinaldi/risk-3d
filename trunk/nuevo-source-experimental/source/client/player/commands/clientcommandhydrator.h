#ifndef __CLIENTCOMMANDHYDRATOR_H__
#define __CLIENTCOMMANDHYDRATOR_H__

#include<string>
#include<map>
#include "clientcommand.h"
#include "battleresultclientcommand.h"
#include "moveclientcommand.h"
#include "populateclientcommand.h"
#include "surrenderclientcommand.h"
#include "quitclientcommand.h"
#include "../../../common/model/game.h"
#include "../../../common/smartpointer/referencecountptr.h"


class ClientCommandHydrator {
    /**
     * Atributos privados de la clase ClientCommandHydrator.
     */
    private:
        /**
         * Almacena una referencia al Game.
         */
        ReferenceCountPtr<Game> game;
        /**
         * Almacena el mapa de comandos de cliente.
         */
        std::map<std::string, ReferenceCountPtr<ClientCommand> > clientCommandList;
    /**
     * Metodos publicos de la clase ClientCommandHydrator.
     */
    public:
        /**
         * Constructor de la clase ClientCommandHydrator.
         */
        ClientCommandHydrator(ReferenceCountPtr<Game>& game);
        /**
         * Devuelve un booleano indicando si un tipo es un comando de cliente
         * o no.
         */
        bool isClientCommand(const std::string& commandName);
        /**
         * Crea un comando del cliente y lo devuelve.
         */
        ReferenceCountPtr<ClientCommand> createCommand(const std::string& commandName, const std::string& xml);
        /**
         * Destructor virtual de la clase ClientCommandHydrator.
         */
        virtual ~ClientCommandHydrator();
};

#endif /** __CLIENTCOMMANDHYDRATOR_H__ */

