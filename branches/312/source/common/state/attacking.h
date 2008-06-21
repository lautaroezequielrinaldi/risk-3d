#ifndef ATTACKING_H_
#define ATTACKING_H_

class Attack;
#include "state.h"

class Attacking : public State
{

	public:

		//Attacking(ReferenceCountPtr<GameManager>& gameManager);
		Attacking(ReferenceCountPtr<GameManager> & gameManager);
		virtual ~Attacking();

		 virtual bool attack(Attack & command);
		
	    
};

#endif /*ATTACKING_H_*/
