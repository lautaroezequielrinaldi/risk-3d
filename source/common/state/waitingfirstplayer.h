#ifndef WAITINGFIRSTPLAYER_H_
#define WAITINGFIRSTPLAYER_H_

#include "state.h"

class JoinGame;

class WaitingFirstPlayer : public State
{

	public:

	WaitingFirstPlayer(ReferenceCountPtr<GameManager> & gameManager);
		
	virtual ~WaitingFirstPlayer();
		
	virtual bool joinGame(JoinGame & command); 
};

#endif /*WAITINGFIRSTPLAYER_H_*/
