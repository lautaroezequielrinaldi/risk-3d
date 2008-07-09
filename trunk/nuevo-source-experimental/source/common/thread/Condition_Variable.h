#ifndef CONDITION_VARIABLE_H_
#define CONDITION_VARIABLE_H_

#include "mutex.h"
#include <pthread.h>

class Condition_Variable
{
	
	private:
	
		pthread_cond_t condicion;
		
		Condition_Variable(const Condition_Variable& );
		Condition_Variable& operator=(const Condition_Variable&);
		
	
	public:
	
		Condition_Variable();
		
		virtual ~Condition_Variable();
		
		int wait(Mutex & mutex) ;
		
		int signal ();
		
		
};

#endif /*CONDITION_VARIABLE_H_*/
