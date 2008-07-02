/**
 * TP3 - 2008.1
 * Taller de programación - 7542
 * @author Carlos Pantelides 74901
 */
#include "lock.h"
#include <iostream>

Lock::Lock(Mutex &mutex):mutex(mutex){
	this->mutex.lock();
}

Lock::~Lock(){
	mutex.unlock();
}
