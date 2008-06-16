#ifndef WAITINGPLAYER_H_
#define WAITINGPLAYER_H_

#include "state.h"

class WaitingPlayer : public State
{

	public:

		WaitingPlayer();
		
		~WaitingPlayer();
		
	                   virtual bool joinGame(JoinGame & command); 
};

#endif /*WAITINGPLAYER_H_*/
