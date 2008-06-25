#ifndef __WAITING_H__
#define __WAITING_H__

#include "state.h"

class Waiting : public State
{

	public:

	Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
	virtual ~Waiting();
	
	bool attack(Attack & command);
	bool defend(Defend & command);
	bool youAre(YouAre & command);
	bool turnToAttack(TurnToAttack & command);

};

#endif /*__WAITING_H__*/
