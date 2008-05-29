/**
 * TP4 - 2008.1
 * Taller de programación - 7542
 * @author Carlos Pantelides 74901
 */

#include "lock.h"
#include "cancelable.h"

void Cancelable::cancel() {
	Lock (*this->getMutex());
	canceled=true;
}

bool Cancelable::isCanceled() {
	Lock (*this->getMutex());
	return canceled;
}

Cancelable::Cancelable() {
	canceled   = false;
}

Cancelable::~Cancelable(){}
