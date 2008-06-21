#ifndef __CONQUERCOUNTRIESGAMECARD_H__
#define __CONQUERCOUNTRIESGAMECARD_H__

#include<string> // Para definicion de std::string
#include<map> // Para definicion de std::map.
#include<sstream> // Para definicion de std::ostringstream.
#include "gamecard.h" // Para definicion de GameCard.
#include "player.h" // Para definiciòn de Countries.
#include "game.h" // Para definiciòn de Game.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de 
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es definir una carta de juego para conquistar un numero de paises
 * determinado.
 */
class ConquerCountriesGameCard: public GameCard {
    /**
     * Atributos privados de la clase ConquerCountriesGameCard.
     */
    private:
        /**
         * Almacena el numero de paises a conquistar.
         */
        int countryCount;

    /**
     * Mètodos privados de la clase ConquerCountriesGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ConquerCountriesGameCard.
         */
        ConquerCountriesGameCard(const ConquerCountriesGameCard& otherInstance);
        /**
         * Operador de asignacion de la clase ConquerCountriesGameCard.
         */
        ConquerCountriesGameCard& operator=(
            const ConquerCountriesGameCard& otherInstance);

    /**
     * Mètodos pùblicos de la clase ConquerCountriesGameCard.
     */
    public:
        /**
         * Constructor de la clase ConquerCountriesGameCard.
         */
        ConquerCountriesGameCard(const std::string& gameCardName,
			int countryCount);
        /**
         * Metodo que devuelve la cantidad de paises a conquistar.
         */
        int getCountryCount();
        /**
         * Mètodo que valida la carta de juego.
         */
        bool execute(ReferenceCountPtr<GameManager>& gameManager);
        /**
         * Serializa la carta de juego.
         */
        std::map<std::string, std::string> toString();
        /**
         * Destructor virtual de la clase ConquerCountriesGameCard.
         */
        ~ConquerCountriesGameCard();
};

#endif /** __CONQUERCOUNTRIESGAMECARD_H__ */

