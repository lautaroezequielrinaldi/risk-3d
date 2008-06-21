#ifndef DEFENDING_H_
#define DEFENDING_H_

#include "state.h"
class Defend;

class Defending : public State
{

	public:
	
		Defending(ReferenceCountPtr<GameManager> & gameManager);
	
		virtual ~Defending();
		
		virtual bool defend(Defend & command);
		
};

#endif /*DEFENDING_H_*/
