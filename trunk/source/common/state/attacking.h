#ifndef ATTACKING_H_
#define ATTACKING_H_

#include "state.h"

class Attacking : public State
{

	public:

		Attacking(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
		virtual ~Attacking();

		virtual bool attack(Attack & command);
		
		virtual bool noMore(NoMore & command);

		virtual void accept(StateObserver* observer);
};

#endif /*ATTACKING_H_*/
