#ifndef OCCUPYING_H_
#define OCCUPYING_H_

#include "state.h"

class Occupying : public State
{
	public:
	
		Occupying();
	
		~Occupying();
	virtual bool populate(Populate & command);		
};

#endif /*OCCUPYING_H_*/
