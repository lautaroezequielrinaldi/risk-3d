#include "stateobservable.h"
#include "stateobserver.h"

StateObservable::StateObservable() {
	// No realiza ninguna accion.
}

void StateObservable::notifyStateChanged(State& state) {
	std::list<StateObserver*>::iterator iter;

	for (iter = observerList.begin(); iter != observerList.end(); ++iter) {
		StateObserver* observer = *iter;
		state.accept(observer);
	}
}

void StateObservable::registerObserver(StateObserver* observer) {
	this->observerList.push_back(observer);
}

void StateObservable::unregisterObserver(StateObserver* observer) {
	this->observerList.remove(observer);
}

StateObservable::~StateObservable() {
	// No realiza ninguna accion.
}

