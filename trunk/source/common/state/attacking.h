#ifndef ATTACKING_H_
#define ATTACKING_H_

#include "state.h"

class Attacking : public State
{

	public:

		Attacking(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
		virtual ~Attacking();

		 virtual bool attack(Attack & command);
		
	    
};

#endif /*ATTACKING_H_*/
