/**
 * Standard C++ Library Includes.
 */
#include<cstdlib> // Para definiciòn de NULL.

/**
 * POSIX Thread Library Includes.
 */
// No necesita incluir ninguna libreria POSIX Thread.

/**
 * Project Includes.
 */
#include "mutex.h" // Para definiciòn de Mutex.

Mutex::Mutex() {
	// Inicializa el mutex POSIX Thread que encapsula.
	pthread_mutex_init(&(this->mutex), NULL);
}

void Mutex::lock() {
	// Ejerce un lock sobre el mutex POSIX Thread que encapsula.
	pthread_mutex_lock(&(this->mutex));
}

bool Mutex::tryLock() {
	// Define el valor de retorno
	int  returnValue;

	// Trata de ejercer un lock sobre el POSIX Thread que encapsula.
	returnValue = pthread_mutex_trylock(&(this->mutex));

	// Evalua el valor de retorno
	if (returnValue == 0) {
		return true;
	} else {
		return false;
	}
}

void Mutex::unlock() {
	// Ejerce un unlock sobre el mutex POSIX Thread que encapsula.
	pthread_mutex_unlock(&(this->mutex));
}

Mutex::~Mutex() {
	// Destruye el mutex POSIX Thread que encapsula.
	pthread_mutex_destroy(&(this->mutex));
}

