#ifndef DEFENDING_H_
#define DEFENDING_H_

#include "state.h"


class Defending : public State
{

	public:
	
		Defending();
	
		virtual ~Defending();
		
		virtual bool defend(Defend & command);
		
};

#endif /*DEFENDING_H_*/
