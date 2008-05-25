#ifndef __MAPA_H__
#define __MAPA_H__

#include<string> // Para definiciòn de std::string
#include<list> // Para definiciòn de std::list
#include "pais.h" // Para definiciòn de Pais.
#include "continente.h" // Para definiciòn de Continente.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es modelar al mapa de nuestro modelo.
 */
class Mapa {
    /**
     * Tipos de datos pùblicos de la clase Mapa.
     */
    public:
        /**
         * Defino el tipo de dato IteradorPais de la clase Mapa.
         */
        typedef std::list< ReferenceCountPtr<Pais> >::iterator IteradorPais;
        /**
         * Defino el tipo de dato IteradorContinente de la clase Mapa.
         */
        typedef std::list< ReferenceCountPtr<Continente> >::iterator
            IteradorContinente;

    /**
     * Atributos privados de la clase Mapa.
     */
    private:
        /**
         * Almacena la lista de paises del Mapa.
         */
        std::list< ReferenceCountPtr<Pais> > paises;
        /**
         * Almacena la lista de continentes del Mapa.
         */
        std::list< ReferenceCountPtr<Continente> > continentes;

    /**
     * Mètodos privados de la clase Mapa.
     */
    private:
        /**
         * Constructor copia de la clase Mapa.
         */
        Mapa(const Mapa& otherInstance);
        /**
         * Operador de asignaciòn de la clase Mapa.
         */
        Mapa& operator=(const Mapa& otherInstance);

    /**
     * Mètodos pùblicos de la clase Mapa.
     */
    public:
        /**
         * Constructor de la clase Mapa.
         */
        Mapa();
        /**
         * Mètodo cuyo propòsito es agregar un pais al Mapa.
         */
        void agregarPais(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es remover un pais del Mapa.
         */
        void removerPais(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es obtener un pais del Mapa.
         */
        ReferenceCountPtr<Pais> obtenerPais(const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es agregar un continente al Mapa.
        */
        void agregarContinente(const ReferenceCountPtr<Continente>& continente);
        /**
         * Mètodo cuyo propòsito es remover un continente del Mapa.
         */
        void removerContinente(const ReferenceCountPtr<Continente>& continente);
        /**
         * Mètodo cuyo propòsito es obtener un continente del Mapa.
         */
        ReferenceCountPtr<Continente> obtenerContinente(
            const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es obtener un iterador apuntando al primer
         * paìs del Mapa.
         */
        IteradorPais primerPais();
        /**
         * Mètodo cuyo propòsito es obtener un iterador apuntando al ùltimo
         * paìs del Mapa.
         */
        IteradorPais ultimoPais();
        /**
         * Mètodo cuyo propòsito es obtener un iterador apuntando al primer
         * continente del Mapa.
         */
        IteradorContinente primerContinente();
        /**
         * Mètodo cuyo propòsito es obtener un iterador apuntando al ùltimo
         * continente del Mapa.
         */
        IteradorContinente ultimoContinente();
        /**
         * Destructor de la clase Mapa.
         */
        ~Mapa();
};

#endif /** __MAPA_H__ */

