#ifndef __STATEOBSERVABLE_H__
#define __STATEOBSERVABLE_H__

#include<list>
#include "state.h"

/**
 * Forward declaration de la clase StateObserver.
 */
class StateObserver;

class StateObservable {
	/**
	 * Atributos privados de la clase StateObservable.
	 */
	std::list<StateObserver*> observerList;

	/**
	 * Metodos protegidos de la clase StateObservable.
	 */
	protected:
		/**
		 * Constructor de la clase StateObservable.
		 */
		StateObservable();
		/**
		 * Notificar cambio de estado.
		 */
		void notifyStateChanged(State& state);
	/**
	 * Metodos publicos de la clase StateOsverbale.
	 */
	public:
		/**
		 * Registra un observer en la lista de observers.
		 */
		void registerObserver(StateObserver* observer);
		/**
		 * Desregistra un observer de la lista de observers.
		 */
		void unregisterObserver(StateObserver* observer);
		/**
		 * Destructor virtual de la clase StateOsvervable.
		 */
		virtual ~StateObservable();
};

#endif /** __STATEOBSERVABLE_H__ */

