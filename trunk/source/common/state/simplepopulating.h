#ifndef SIMPLEPOPULATING_H_
#define SIMPLEPOPULATING_H_

#include "state.h"

class SimplePopulating : public State
{
	
	public:
	
		SimplePopulating();
	
		~SimplePopulating();
                virtual bool populate(Populate & command);
};

#endif /*SIMPLEPOPULATING_H_*/
