/**
 * TP3 - 2008.1
 * Taller de programación - 7542
 * @author dado en clase martes
 */
#include "threaded.h"
#include <iostream>

Threaded::Threaded(){
	last_error=0;
}

int Threaded::start(){
	return last_error = pthread_create(&thread, 0, start_routine, this);
}

void * Threaded::start_routine( void * arg) {
	Threaded * r = (Threaded *) arg;
	void * result;
	result = r->run();
	return result;
}

void * Threaded::join(){
	void * result;
	last_error = pthread_join(thread, &result);
	return result;
}
