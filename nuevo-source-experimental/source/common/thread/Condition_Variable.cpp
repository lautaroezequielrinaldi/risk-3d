#include "Condition_Variable.h"


Condition_Variable::Condition_Variable()
{
	pthread_cond_init (& this->condicion, NULL);
	
}

Condition_Variable::~Condition_Variable()
{
	pthread_cond_destroy(& this->condicion);
}

int Condition_Variable::wait(Mutex & mutex) {
	
	return pthread_cond_wait(& this->condicion , & mutex.getPthreadMutex() );
}

int Condition_Variable::signal (){
	
	return pthread_cond_signal(& this->condicion);
}

