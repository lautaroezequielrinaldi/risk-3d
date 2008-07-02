#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include<list> // Para definiciòn de std::list

/**
 * Declaraciòn Forward de la clase Observer.
 */
class Observer;

/**
 * Clase cuyo propòsito es representar un objeto observable y notificar
 * a observadores de cambios en el mismo para que èstos se actualicen.
 * Es una clase abstracta.
 */
class Subject {
    /**
     * Atributos de la clase Subject.
     */
    private:
        /**
         * Almacena la lista de observadores registrados a notificar.
         */
        std::list<Observer*> observerList;

    /**
     * Mètodos pùblicos de la clase Subject.
     */
    public:
        /**
         * Contructor de la clase Subject.
         */
        Subject();
        /**
         * Registra un observador a la lista de observadores a ser notificados.
         */
        void registerObserver(Observer* observer);
        /**
         * Desregistra un observador a la lista de observadores a ser
         * notificados.
         */
        void unregisterObserver(Observer* observer);
        /**
         * Notifica a todos los observadores de un cambio en el sujeto.
         */
        void notify();
        /**
         * Destructor virtual de la clase Subject.
         */
        virtual ~Subject();
};

#endif /** __SUBJECT_H__ */

