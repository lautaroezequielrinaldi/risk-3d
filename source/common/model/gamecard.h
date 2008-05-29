#ifndef __GAMECARD_H__
#define __GAMECARD_H__

#include "../parser/serializable.h" // Para definiciòn de Serializable.

/**
 * Clase cuyo propòsito es representar una carta de juego.
 */
class GameCard: public Serializable {
    /**
     * Mètodos pùblicos de la clase GameCard.
     */
    public:
        virtual bool execute(const ReferenceCountPtr<Player>& player,
            const ReferenceCountPtr<Game>& game) = 0;
};

#endif /** __GANECARD_H__ */

