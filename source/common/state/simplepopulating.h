#ifndef SIMPLEPOPULATING_H_
#define SIMPLEPOPULATING_H_

#include "state.h"

class SimplePopulating : public State
{
	
	public:
	
		SimplePopulating(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
		virtual ~SimplePopulating();
                virtual bool populate(Populate & command);
};

#endif /*SIMPLEPOPULATING_H_*/
