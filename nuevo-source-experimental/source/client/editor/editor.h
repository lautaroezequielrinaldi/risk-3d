#ifndef __EDITOR_H__
#define __EDITOR_H__

#include<string> // Para definicion de std::string.
#include "subject.h" // Para definiciòn de Subject.
#include "../../common/model/mapa.h" // Para definiciòn de Mapa.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar al editor de mapas del juego RISK-3D.
 */
class Editor: public Subject {
    /**
     * Atributos privados de la clase Editor.
     */
    private:
        /**
         * Almacena el mapa que va a usar el editor.
         */
        ReferenceCountPtr<Mapa> mapa;
		/**
		 * Almacena el nombre de la imagen del mapa.
		 */
		std::string imageFileName;
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
        Editor(const std::string& fileName);
        /**
         * Establece el mapa con el cual va a trabajar el editor.
         */
        void setMapa(const ReferenceCountPtr<Mapa>& mapa);
        /**
         * Devuelve el mapa con el cual va a trabajar el editor.
         */
        ReferenceCountPtr<Mapa>& getMapa();
		/**
		 * Establece el nombre de la imagen del mapa.
		 */
		void setImageFileName(const std::string& imageFileName);
		/**
		 * Obtiene el nombre de la imagen del mapa.
		 */
		std::string& getImageFileName();
        /**
         * Destructor virtual de la clase Editor.
         */
        virtual ~Editor();
};

#endif /** __EDITOR_H__ */

