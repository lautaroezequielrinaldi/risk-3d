#ifndef WAITINGFIRSTPLAYER_H_
#define WAITINGFIRSTPLAYER_H_

#include "state.h"

class WaitingFirstPlayer : public State
{

	public:

	WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
	virtual ~WaitingFirstPlayer();
		
	virtual bool joinGame(ServerJoinGame & command);

	virtual void accept(StateObserver* observer); 
};

#endif /*WAITINGFIRSTPLAYER_H_*/
