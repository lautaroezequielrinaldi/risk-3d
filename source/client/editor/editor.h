#ifndef __EDItOR_H__
#define __EDITOR_H__

#include<string> // Para definiciòn de std::string
#include "../../common/model/mapa.h" // Para definiciòn de Mapa
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr

/**
 * Clase cuyo propòsito es representar al editor de mapas.
 */
class Editor {
    /**
     * Atributos privados de la clase Editor.
     */
    private:
        /**
         * Almacena un puntero al mapa a ser editado por el editor.
         */
        ReferenceCountPtr<Mapa> mapa;

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
         * Constructor de la clase Editor.
         */
        Editor(const std::string fileName);
        /**
         * Mètodo cuyo propòsito es persistir el mapa en disco.
         */
        void onSaveClicked();
        /**
         * Destructor virtual de la clase Editor.
         */
        virtual ~Editor();
};
 
#endif /** __EDITOR_H__ */

