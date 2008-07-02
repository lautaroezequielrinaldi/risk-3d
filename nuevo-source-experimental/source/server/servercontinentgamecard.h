#ifndef __SERVERCONTINENTGAMECARD_H__
#define __SERVERCONTINENTGAMECARD_H__

#include<string> // Para definiciòn de std::string.
#include<map> // Para definicion de std::map.
#include "../common/model/player.h" // Para definiciòn de Player.
#include "../common/model/game.h" // Para definiciòn de Game.
#include "../common/model/conquercontinentgamecard.h" // Para definiciòn de ServerContinentGameCard.
#include "gamecardvalidator.h"
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo proposito es representar la carta de juego conquistar continente.
 */
class ServerContinentGameCard: public GameCardValidator, public ConquerContinentGameCard {
    /**
     * Mètodos privados de la clase ServerContinentGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ServerContinentGameCard.
         */
        ServerContinentGameCard(const ServerContinentGameCard&
            otherInstance);
        /**
         * Operador de asignacion de la clase ServerContinentGameCard.
         */
        ServerContinentGameCard& operator=(const ServerContinentGameCard&
            otherInstance);

    /**
     * Mètodos pùblicos de la clse ServerContinentGameCard.
     */
    public:
        /**
         * Constructor de la clase ServerContinentGameCard.
         */
        ServerContinentGameCard(const std::string& name,
            const std::string& continentName);
        /**
         * Mètodo que valida la carta de juego.
         */
        bool validate(ReferenceCountPtr<GameManager>& gameManager);
        /**
         * Destructor virtual de la clase ServerContinentGameCard.
         */
        virtual ~ServerContinentGameCard();
};

#endif /** __SERVERCONTINENTGAMECARD_H__ */

