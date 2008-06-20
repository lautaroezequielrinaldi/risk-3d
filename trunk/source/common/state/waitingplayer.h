#ifndef WAITINGPLAYER_H_
#define WAITINGPLAYER_H_

#include "state.h"

class WaitingPlayer : public State
{

	public:

	WaitingPlayer();
	
	virtual ~WaitingPlayer();
	
	virtual bool joinGame(JoinGame & command); 
	virtual bool readyToPlay(ReadyToPlay & command);

};

#endif /*WAITINGPLAYER_H_*/
