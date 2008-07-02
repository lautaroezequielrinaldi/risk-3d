#ifndef __SERVERCOUNTRIESGAMECARD_H__
#define __SERVERCOUNTRIESGAMECARD_H__

#include<string> // Para definicion de std::string
#include<map> // Para definicion de std::map.
#include<sstream> // Para definicion de std::ostringstream.
#include "../common/model/conquercountriesgamecard.h" // Para definicion de GameCard.
#include "../common/model/player.h" // Para definiciòn de Countries.
#include "../common/model/game.h" // Para definiciòn de Game.
#include "gamecardvalidator.h"
#include "../common/smartpointer/referencecountptr.h" // Para definiciòn de 
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es definir una carta de juego para conquistar un numero de paises
 * determinado.
 */
class ServerCountriesGameCard: public GameCardValidator, public ConquerCountriesGameCard {
    /**
     * Mètodos privados de la clase ServerCountriesGameCard.
     */
    private:
        /**
         * Constructor copia de la clase ServerCountriesGameCard.
         */
        ServerCountriesGameCard(const ServerCountriesGameCard& otherInstance);
        /**
         * Operador de asignacion de la clase ServerCountriesGameCard.
         */
        ServerCountriesGameCard& operator=(
            const ServerCountriesGameCard& otherInstance);

    /**
     * Mètodos pùblicos de la clase ServerCountriesGameCard.
     */
    public:
        /**
         * Constructor de la clase ServerCountriesGameCard.
         */
        ServerCountriesGameCard(const std::string& gameCardName,
			int countryCount);
        /**
         * Mètodo que valida la carta de juego.
         */
        bool validate(ReferenceCountPtr<GameManager>& gameManager);
        /**
         * Serializa la carta de juego.
         */
        std::map<std::string, std::string> toString();
        /**
         * Destructor virtual de la clase ServerCountriesGameCard.
         */
        ~ServerCountriesGameCard();
};

#endif /** __SERVERCOUNTRIESGAMECARD_H__ */

