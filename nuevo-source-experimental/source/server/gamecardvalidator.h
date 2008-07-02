#ifndef __GAMECARDVALIDATOR_H__
#define __GAMECARDVALIDATOR_H__

#include "../common/model/gamemanager.h"
#include "../common/smartpointer/referencecountptr.h"

class GameCardValidator {
    /**
     * Metodos protegidos de la clase GameCardValidator.
     */
    protected:
        /**
         * Constructor de la clase GameCardValidator.
         */
        GameCardValidator();
    /**
     * Mètodos publicos de la clase GameCardValidator.
     */
    ublic:
       /**
        * Valida una carta de juego.
        */
        virtual bool validate(ReferenceCountPtr<GameManager>& gameManager) = 0;
        /**
         * Destructor virtual de la clase GameCardValidator.
         */
        virtual ~GameCardValidator();
};

#endif /** __GAMECARDVALIDATOR_H__ */

