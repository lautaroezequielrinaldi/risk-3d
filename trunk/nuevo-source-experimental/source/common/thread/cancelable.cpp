#include "lock.h"
#include "cancelable.h"

#include <iostream>

void Cancelable::cancel() {
	Lock (*this->getMutex());
	canceled=true;
	std::cerr<<" thread cancelado" <<std::endl;
}

bool Cancelable::isCanceled() {
	Lock (*this->getMutex());
	return canceled;
}

Cancelable::Cancelable() {
	canceled   = false;
}

Cancelable::~Cancelable(){}
