#include "stateobserver.h"

StateObserver::StateObserver() {
	// No realiza ninguna accion.
}

void StateObserver::stateChanged(const Attacking& state) {
	// No realiza ninguna accion.
}

void StateObserver::stateChanged(const Defending& state) {
    // No realiza ninguna accion.
}

void StateObserver::stateChanged(const Moving& state) {
    // No realiza ninguna accion.
}


void StateObserver::stateChanged(const Occupying& state) {
    // No realiza ninguna accion.
} 

void StateObserver::stateChanged(const Populating& state) {
    // No realiza ninguna accion.
}

void StateObserver::stateChanged(const SimplePopulating& state) {
    // No realiza ninguna accion.
}

void StateObserver::stateChanged(const Waiting& state) {
    // No realiza ninguna accion.
}

void StateObserver::stateChanged(const WaitingMapSelection& state) {
    // No realiza ninguna accion.
}

void StateObserver::stateChanged(const WaitingPlayer& state) {
	// No realiza ninguna accion.
}

void StateObserver::stateChanged(const WaitingFirstPlayer& state) {
    // No realiza ninguna accion.
}

StateObserver::~StateObserver() {
	// No realiza ninguna accion.
}

