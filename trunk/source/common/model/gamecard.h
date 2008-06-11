#ifndef __GAMECARD_H__
#define __GAMECARD_H__

#include<string> // Para definiciòn de std::string.
#include "player.h" // Para definiciòn de Player.
#include "game.h" // Para definiciòn de Game.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
//ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar una carta de juego.
 */
class GameCard {
    /**
     * Atributos privados de la clase GameCard.
     */
    private:
        /**
         * Almacena el nombre de la GameCard.
         */
        std::string name;

    /**
     * Mètodos pùblicos de la clase GameCard.
     */
    public:
        /**
         * Constructor de la clase GameCard.
         */
        GameCard(const std::string& name);
        /**
         * Establece el nombre de la GameCard.
         */
        void setName(const std::string& name);
        /**
         * Obtiene el nombre de la GameCard.
         */
        std::string getName();

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

