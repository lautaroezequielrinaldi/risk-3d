#ifndef __SERVERPLAYERGAMECARD_H__
#define __SERVERPLAYERGAMECARD_H__

#include<string> // Para definicion de std::string.
#include<map> // Para definicion de std::map.
#include<sstream> // Para definicion de std::ostringstream.
#include "../common/model/conquerplayergamecard.h" // Para definicion de GameCard.
#include "gamecardvalidator.h"
#include "../common/smartpointer/referencecountptr.h" // Para definiciòn de 
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es definir una carta de juego para eliminar a un
 * jugador determinado.
 */
class ServerPlayerGameCard: public GameCardValidator, public ConquerPlayerGameCard {
    /**
     * Mètodos privados de la clase ServerPlayerGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ServerPlayerGameCard.
         */
        ServerPlayerGameCard(const ServerPlayerGameCard& otherInstance);
        /**
         * Operador de asignacion de la clase ServerPlayerGameCard.
         */
        ServerPlayerGameCard& operator=(
            const ServerPlayerGameCard& otherInstance);

    /**
     * Mètodos pùblicos de la clase ServerPlayerGameCard.
     */
    public:
        /**
         * Constructor de la clase ServerPlayerGameCard.
         */
        ServerPlayerGameCard(const std::string& gameCardName, int color);
        /**
         * Mètodo que valida la carta de juego.
         */
        bool validate(ReferenceCountPtr<GameManager>& gameManager);
        /**
         * Destructor virtual de la clase ServerPlayerGameCard.
         */
        ~ServerPlayerGameCard();
};

#endif /** __SERVERPLAYERGAMECARD_H__ */

