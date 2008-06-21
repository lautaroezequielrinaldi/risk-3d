#ifndef __WAITINGMAPSELECTION_H__
#define __WAITINGMAPSELECTION_H__

#include "state.h"

class JoinGame;
class SelectMap;
class ReadyToPlay;

class WaitingMapSelection : public State
{

	public:

	WaitingMapSelection(ReferenceCountPtr<GameManager> & gameManager);
		
	virtual ~WaitingMapSelection();
		
	virtual bool selectMap(SelectMap & command); 
	virtual bool joinGame(JoinGame & command);
	virtual bool readyToPlay(ReadyToPlay & command);
};

#endif /*__WAITINGMAPSELECTION_H__*/
