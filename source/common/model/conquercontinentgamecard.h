#ifndef __CONQUERCONTINENTGAMECARD_H__
#define __CONQUERCONTINENTGAMECARD_H__

#include<string> // Para definiciòn de std::string.
#include<map> // Para definicion de std::map.
#include "player.h" // Para definiciòn de Player.
#include "game.h" // Para definiciòn de Game.
#include "gamecard.h" // Para definiciòn de GameCard.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo proposito es representar la carta de juego conquistar continente.
 */
class ConquerContinentGameCard: public GameCard {
    /**
     * Atributos privados de la clase ConquerContinentGameCard.
     */
    private:
        /**
         * Almacena el nombre del continente a conquistar.
         */
        std::string continentName;

    /**
     * Mètodos privados de la clase ConquerContinentGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ConquerContinentGameCard.
         */
        ConquerContinentGameCard(const ConquerContinentGameCard&
            otherInstance);
        /**
         * Operador de asignacion de la clase ConquerContinentGameCard.
         */
        ConquerContinentGameCard& operator=(const ConquerContinentGameCard&
            otherInstance);

    /**
     * Mètodos pùblicos de la clse ConquerContinentGameCard.
     */
    public:
        /**
         * Obtiene el nombre del continente.
         */
        std::string getContinentName();
        /**
         * Constructor de la clase ConquerContinentGameCard.
         */
        ConquerContinentGameCard(const std::string& name,
            const std::string& continentName);
        /**
         * Mètodo que valida la carta de juego.
         */
        bool execute(ReferenceCountPtr<GameManager>& gameManager);
        /**
         * Se serializa a string.
         */
        std::map<std::string, std::string> toString();
        /**
         * Destructor virtual de la clase ConquerContinentGameCard.
         */
        virtual ~ConquerContinentGameCard();
};

#endif /** __CONQUERCONTINENTGAMECARD_H__ */

