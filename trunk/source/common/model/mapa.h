#ifndef __MAPA_H__
#define __MAPA_H__

#include<string> // Para definiciòn de std::string
#include<vector> // Para definiciòn de std::vector.
#include "pais.h" // Para definiciòn de Pais.
#include "continente.h" // Para definiciòn de Continente.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es modelar al mapa de nuestro modelo.
 */
class Mapa {
    /**
     * Atributos privados de la clase Mapa.
     */
    private:
        /**
         * Almacena la lista de paises del Mapa.
         */
        std::vector< ReferenceCountPtr<Pais> > paises;
        /**
         * Almacena la lista de continentes del Mapa.
         */
        std::vector< ReferenceCountPtr<Continente> > continentes;

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
         * Mètodo cuyo propòsito es remover un pais del Mapa.
         */
        void removerContinente(const ReferenceCountPtr<Continente>& continente);
        /**
         * Mètodo cuyo propòsito es obtener un pais del Mapa.
         */
        ReferenceCountPtr<Continente> obtenerPais(const std::string& nombre);
        /**
         * Destructor virtual de la clase Mapa.
         */
        virtual ~Mapa();
};

#endif __MAPA_H__

