#ifndef POPULATING_H_
#define POPULATING_H_

#include "state.h"



class Populating : public State
{
	public:
	
		Populating(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
		virtual ~Populating();
                virtual bool populate(Populate & command);		
};

#endif /*POPULATING_H_*/
