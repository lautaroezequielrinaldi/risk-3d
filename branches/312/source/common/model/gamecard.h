#ifndef __GAMECARD_H__
#define __GAMECARD_H__

#include<string> // Para definiciòn de std::string.
#include<map> // Para definiciòn de std::list.
#include "gamemanager.h" // Para definiciòn de GameManager.
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
         * Devuelve el objeto serializado como pares clave, valor.
         */
        virtual std::map<std::string, std::string> toString() = 0;
        /**
         * Valida la carta de juego para un jugador.
         */
        virtual bool execute(ReferenceCountPtr<GameManager>& gameManager) = 0;
        /**
         * Destructor virtual de la clase GameCard.
         */
        virtual ~GameCard();      
};

#endif /** __GANECARD_H__ */

