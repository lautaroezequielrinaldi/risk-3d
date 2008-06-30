#ifndef OCCUPYING_H_
#define OCCUPYING_H_

#include "state.h"

class Occupying : public State
{
	public:
	
		Occupying(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
		virtual ~Occupying();
	virtual bool populate(Populate & command);
	virtual void accept(StateObserver* observer);
};

#endif /*OCCUPYING_H_*/
