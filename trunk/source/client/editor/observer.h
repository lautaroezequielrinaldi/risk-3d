#ifndef __OBSERVER_H__
#define __OBSERVER_H__

/**
 * Declaraciòn Forward de la clase Subject.
 */
class Subject;

/**
 * Clase cuyo propòsito es representar a un observador de un sujeto en
 * particular. Recibiendo notificaciones de cambio en el sujeto observado.
 * Es una clase abstracta.
 */
class Observer {
    /**
     * Mètodos protegidos de la clase Observer.
     */
    protected:
        /**
         * Constructor de la clase Observer.
         */
        Observer();

    /**
     * Mètodos pùblicos de la clase Observer.
     */
    public: 
        /**
         * Se actualiza en base a cambios realizados en el sujeto observado.
         */
        virtual void update(const Subject* subject) = 0;
        /**
         * Destructor virtual de la clase Observer.
         */
        virtual ~Observer();
};

#endif /** __OBSERVER_H__ */

