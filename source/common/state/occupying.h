#ifndef OCCUPYING_H_
#define OCCUPYING_H_

#include "state.h"
class Populate;

class Occupying : public State
{
	public:
	
		Occupying(ReferenceCountPtr<GameManager> & gameManager);
	
		virtual ~Occupying();
	virtual bool populate(Populate & command);		
};

#endif /*OCCUPYING_H_*/
