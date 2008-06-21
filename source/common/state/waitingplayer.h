#ifndef WAITINGPLAYER_H_
#define WAITINGPLAYER_H_

#include "state.h"

class WaitingPlayer : public State
{

	public:

	WaitingPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
	virtual ~WaitingPlayer();
	
	virtual bool joinGame(JoinGame & command); 
	virtual bool readyToPlay(ReadyToPlay & command);

};

#endif /*WAITINGPLAYER_H_*/
