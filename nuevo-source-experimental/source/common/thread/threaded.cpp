
#include "threaded.h"
#include <iostream>
#include <sys/signal.h>

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

void Threaded::kill(){

	pthread_kill(thread,SIGKILL);		
}


