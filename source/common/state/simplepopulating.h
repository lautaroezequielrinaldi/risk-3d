#ifndef SIMPLEPOPULATING_H_
#define SIMPLEPOPULATING_H_

#include "state.h"

class Populate;

class SimplePopulating : public State
{
	
	public:
	
		SimplePopulating(ReferenceCountPtr<GameManager> & gameManager);
	
		virtual ~SimplePopulating();
                virtual bool populate(Populate & command);
};

#endif /*SIMPLEPOPULATING_H_*/
