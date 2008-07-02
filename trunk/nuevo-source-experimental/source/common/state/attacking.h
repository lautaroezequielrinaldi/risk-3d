#ifndef ATTACKING_H_
#define ATTACKING_H_

#include "state.h"

class Attacking : public State
{

	public:

		Attacking(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
		virtual ~Attacking();

		virtual bool attack(ServerAttack & command);
		
		virtual bool noMore(ServerNoMore & command);

		virtual void accept(StateObserver* observer);
};

#endif /*ATTACKING_H_*/
