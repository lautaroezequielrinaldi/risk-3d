#ifndef __REFERENCECOUNT_H__
#define __REFERENCECOUNT_H__

/**
 * Definiciòn de la clase ReferenceCount que es usada para almacenar la cuenta
 * de referencias de un puntero en particular. Provee metodos para incrementar
 * la cuenta, decrementar la misma y obtener la cuenta de referencias de un
 * puntero.
 */
class ReferenceCount {
    /**
     * Atributos privados de la clase ReferenceCount.
     */
    private:
        /**
         * Almacena la cuenta de referencias de un puntero de la clase
         * ReferenceCount.
         */
        int referenceCount;

    /**
     * Mètodos pùblicos de la clase ReferenceCount.
     */
    public:
        /**
         * Constructor de la clase ReferenceCount.
         * Construye una nueva instancia de la clase ReferenceCount.
         */
        ReferenceCount();

        /**
         * Incrementa la cuenta de referencias de un puntero en uno.
         */
        void increment();

        /**
         * Decrementa la cuenta de referencias de un puntero en uno.
         */
        void decrement();

        /**
         * Obtiene la cuenta de referencias de un puntero.
         */
        int getReferenceCount();

        /**
         * Destructor virtual de la clase ReferenceCount.
         * Destruye una instancia existente de la clase ReferenceCount.
         */
        ~ReferenceCount();
};

#endif /** __REFERENCECOUNT_H__ */

