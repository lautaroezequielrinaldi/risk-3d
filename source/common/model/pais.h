#ifndef __PAIS_H__
#define __PAIS_H__

#include<string> // Para definiciòn de std::string.
#include<list> // Para definiciòn de std::list.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar un pais dentro de nuestro modelo.
 */
class Pais {
    /**
     * Atributos privaods de la clase Pais.
     */
    private:
        /**
         * Almacena el nombre del Pais.
         */
        std::string nombre;
        /**
         * Almacena la lista de paises adyacentes,
         */
        std::list< ReferenceCountPtr<Pais> > paisesAdyacentes;

    /**
     * Mètodos privados de la clase Pais.
     */
    private:
        /**
         * Constructor copia de la clase Pais.
         */
        Pais(const Pais& otherInstance);
        /**
         * Operador de asignaciòn de la clase Pais.
         */
        Pais& operator=(const Pais& otherInstance);

    /**
     * Mètodos pùblicos de la clase Pais.
     */
    public:
        /**
         * Constructor de la clase Pais.
         */
        Pais(const std::string nombre);
        /**
         * Mètodo cuyo propòsito es obtiener el nombre del Pais.
         */
        std::string getNombre();
        /**
         * Mètodo cuyo propòsito es establecer el nombre del Pais.
         */
        void setNombre(const std::string& nombre);
        /**
         * Mètodo cuyo propòsito es agregar a un pais como adyacente.
         */
        void agregarAdyacente(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es remover a un pais adyacente.
         */
        void removerAdyacente(const ReferenceCountPtr<Pais>& pais);
        /**
         * Mètodo cuyo propòsito es obtener un pais adyacente.
         * NULL si no se encuentra dicho pais adyacente.
         */
        ReferenceCountPtr<Pais> obtenerAdyacente(std::string nombre);
        /**
         * Destructor virtual de la clase Pais.
         */
        virtual ~Pais();
};

#endif /** __PAIS_H__ */

