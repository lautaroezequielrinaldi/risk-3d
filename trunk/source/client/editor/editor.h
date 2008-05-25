#ifndef __EDITOR_H__
#define __EDITOR_H__

#include "subject.h" // Para definiciòn e la clase Subject.

/**
 * Clase cuyo propòsito es representar al editor de mapas del juego RISK-3D.
 */
class Editor: public Subject {
    /**
     * Atributos privados de la clase Editor.
     */
    private:

    /**
     * Mètodos privados de la clase Editor.
     */
    private:
        /**
         * Constructor copia de la clase Editor.
         */
        Editor(const Editor& otherInstance);
        /**
         * Operador de asignaciòn de la clase Editor.
         */
        Editor& operator=(const Editor& otherInstance);

    /**
     * Mètodos pùblicos de la clase Editor.
     */
    public:
        /**
         * Constructor de la clase Editor.
         */
        Editor();
        /**
         * Destructor virtual de la clase Editor.
         */
        virtual ~Editor();
};

#endif /** __EDITOR_H__ */

