#ifndef __CONQUERPLAYERGAMECARD_H__
#define __CONQUERPLAYERGAMECARD_H__

#include<string> // Para definicion de std::string.
#include<map> // Para definicion de std::map.
#include<sstream>
#include "gamecard.h"

/**
 * Clase cuyo propòsito es definir una carta de juego para eliminar a un
 * jugador determinado.
 */
class ConquerPlayerGameCard: public GameCard {
    /**
     * Atributos privados de la clase ConquerPlayerGameCard.
     */
    private:
        /**
         * Almacena el color del jugador a conquistar.
         */
        int color;

    /**
     * Mètodos privados de la clase ConquerPlayerGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ConquerPlayerGameCard.
         */
        ConquerPlayerGameCard(const ConquerPlayerGameCard& otherInstance);
        /**
         * Operador de asignacion de la clase ConquerPlayerGameCard.
         */
        ConquerPlayerGameCard& operator=(
            const ConquerPlayerGameCard& otherInstance);

    /**
     * Mètodos pùblicos de la clase ConquerPlayerGameCard.
     */
    public:
        /**
         * Constructor de la clase ConquerPlayerGameCard.
         */
        ConquerPlayerGameCard(const std::string& gameCardName, int color);
        /**
         * Metodo que devuelve el color del jugador.
         */
        int getColor();
        /**
         * Se serializa a  un string.
         */
        std::map<std::string, std::string> toString();
        /**
         * Destructor virtual de la clase ConquerPlayerGameCard.
         */
        ~ConquerPlayerGameCard();
};

#endif /** __CONQUERPLAYERGAMECARD_H__ */

