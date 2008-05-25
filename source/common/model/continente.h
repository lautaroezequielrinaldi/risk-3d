#ifndef __CONTINENTE_H__
#define __CONTINENTE_H__

#include<string> // Para definiciòn de std::string.
#include<list> // Para definiciòn de std::list.
#include "pais.h" // Para definiciòn de Pais.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar un continente dentro de nuestro
 * modelo.
 */
class Continente {
    /**
     * Tipos de datos pùblicos de la clase Continente.
     */
    public:
        /**
         * Defino el tipo de dato Iterador de la clase Continente.
         */
        typedef std::list< ReferenceCountPtr<Pais> >::iterator Iterador;
    /**
     * Atributos privados de la clase Continente.
     */
    private:
        /**
         * Almacena el nombre del Continente.
         */
        std::string nombre;
        /**
         * Almacena la lista de paises del Continente.
         */
        std::list< ReferenceCountPtr<Pais> > paises;

    /**
     * Mètodos privados de la clase Continente.
     */
    private:
        /**
         * Constructor copia de la clase Continente.
         */
        Continente(const Continente& otherInstance);
        /**
         * Operador de asignaciòn de la clase Continente.
         */
        Continente& operator=(const Continente& otherInstance);

    /**
     * Mètodos pùblicos de la clase Continente.
     */
    public:
        /**
         * Constructor de la clase Continente.
         */
        Continente(const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es obtener el nombre del Continente.
         */
        std::string getNombre();
        /**
         * Mètodo cuyo propósito es establecer el nombre del Continente.
         */
        void setNombre(const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es agregar un pais al Continente.
         */
        void agregarPais(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es remover un pais del Continente.
         */
        void removerPais(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es obtener un pais del Continente.
         * NULL si el pais no se encuentra.
         */
        ReferenceCountPtr<Pais> obtenerPais(const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es obtener un iterador apuntando
         * al primer pais del continente.
         */
        Iterador primerPais();
        /**
         * Mètodo cuyo propòsito es obtene run iterador apuntando
         * al ultimo pais del continente.
         */
        Iterador ultimoPais();
        /**
         * Destructor de la clase Continente.
         */
        ~Continente();
};

#endif /** __CONTINENTE_H__ */

