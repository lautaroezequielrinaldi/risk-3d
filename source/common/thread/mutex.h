#ifndef __MUTEX_H__
#define __MUTEX_H__

/**
 * Standard C++ Library Includes.
 */
// No necesita inclur ninguna libreria estandard C++.

/**
 * POSIX Thread Library Includes.
 */
#include<pthread.h>

/**
 * Project Includes.
 */
// No necesita incluir ninguna declaraciòn del proyecto.

class Mutex {
/**
 * Definiciòn de atributos privados de la clase Mutex.
 */
private:
	/**
 	 * Atributo de tipo pthread_mutex_t representando el POSIX Thread mutex
 	 * a encapsular.
 	 */
	pthread_mutex_t mutex;

/**
 * Definiciòn de mètodos privados de la clase Mutex.
 */
private:
	/**
 	 * Constructor copia de la clase Mutex.
 	 */
	Mutex(const Mutex& otherInstance);

	/**
 	 * Operador de asignaciòn de la clase Mutex.
 	 */
	Mutex& operator=(const Mutex& otherInstance);

/**
 * Definiciòn de mètodos publicos de la clase Mutex.
 */
public:
	/**
 	 * Constructor de la clase Mutex.
 	 */
	Mutex();

	/**
 	 * Mètodo cuyo propòsito es ejercer un lock sobre el mutex, dejando
 	 * el hilo de ejecuciòn dormido si el mutex esta lockeado.
 	 */
	void lock();

	/**
 	 * Mètodo cuyo propòsito es tratar de ejercer un lock sobre el mutex,
 	 * devolviendo un valor bool indicando el resultado de la operaciòn,
 	 * true si fue exitosa y false si no, a diferencia del mètodo lock,
 	 * èste no deja el hilo de ejecuciòn dormido si el mutex esta lockeado.
 	 */
	bool tryLock();

	/**
 	 * Mètodo cuyo propòsito es ejercer un unlock sobre el mutex, dejandolo
 	 * disponible para ser lockeado por otro hilo de ejecuciòn en espera.
 	 */
	void unlock();

	/**
 	 * Destructor virtual de la clase Mutex.
 	 */
	virtual ~Mutex();
};

#endif /** __MUTEX_H__ */

