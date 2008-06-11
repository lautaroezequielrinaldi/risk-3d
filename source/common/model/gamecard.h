#ifndef __GAMECARD_H__
#define __GAMECARD_H__

#include "player.h" // Para definiciòn de Player.
#include "game.h" // Para definiciòn de Game.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
//ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar una carta de juego.
 */
class GameCard {
    /**
     * Mètodos pùblicos de la clase GameCard.
     */
    public:
        /**
         * Constructor de la clase GameCard.
         */
        GameCard();
        /**
         * Valida la carta de juego para un jugador.
         */
        virtual bool execute(const ReferenceCountPtr<Player>& player,
            const ReferenceCountPtr<Game>& game) = 0;
        /**
         * Destructor virtual de la clase GameCard.
         */
        virtual ~GameCard();      
};

#endif /** __GANECARD_H__ */

