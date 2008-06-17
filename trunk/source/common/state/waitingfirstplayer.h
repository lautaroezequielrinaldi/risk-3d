#ifndef WAITINGFIRSTPLAYER_H_
#define WAITINGFIRSTPLAYER_H_

#include "state.h"

class WaitingFirstPlayer : public State
{

	public:

	WaitingFirstPlayer();
		
	~WaitingFirstPlayer();
		
	virtual bool joinGame(JoinGame & command); 
};

#endif /*WAITINGFIRSTPLAYER_H_*/
